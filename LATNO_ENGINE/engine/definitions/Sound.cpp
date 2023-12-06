#include "../declarations/Sound.h"

#include "dr_wav/dr_wav.h"

namespace Latno
{

	struct ReadWavData
	{
		unsigned int channels = 0;
		unsigned int sampleRate = 0;
		drwav_uint64 totalPCMFrameCount = 0;
		std::vector<uint16_t> pcmData;
		drwav_uint64 getTotalSamples() { return totalPCMFrameCount * channels; }
	};

#define DR_WAV_IMPLEMENTATION

	std::string Sound::s_filename;

	void Sound::play() {
		isPlaying = true;
		audioThread = std::thread([this]() {
			playAudioFile();
			});
	}


	ReadWavData Sound::GetWavData(std::string file)
	{
		ReadWavData monoData;
		drwav_int16* pSampleData = drwav_open_file_and_read_pcm_frames_s16(file.c_str(), &monoData.channels, &monoData.sampleRate, &monoData.totalPCMFrameCount, nullptr);

		if (pSampleData == NULL) {
			std::cerr << "failed to load audio file" << std::endl;
			drwav_free(pSampleData, nullptr); //todo use raii to clean this up
			// APP END
		}
		if (monoData.getTotalSamples() > drwav_uint64(std::numeric_limits<size_t>::max()))
		{
			std::cerr << "too much data in file for 32bit addressed vector" << std::endl;
			drwav_free(pSampleData, nullptr);
			// APP END
		}

		monoData.pcmData.resize(size_t(monoData.getTotalSamples()));
		std::memcpy(monoData.pcmData.data(), pSampleData, monoData.pcmData.size() * /*twobytes_in_s16*/2);
		drwav_free(pSampleData, nullptr);
		return monoData;
	}

	void Sound::playAudioFile()
	{
		isPlaying = true;

		ALCdevice* device = alcOpenDevice(nullptr);
		if (!device) {
			std::cerr << "Failed to initialize OpenAL device" << std::endl;
			return;
		}

		ALCcontext* context = alcCreateContext(device, nullptr);
		if (!context) {
			std::cerr << "Failed to create OpenAL context" << std::endl;
			alcCloseDevice(device);
			return;
		}

		if (!alcMakeContextCurrent(context)) {
			std::cerr << "Failed to make OpenAL context current" << std::endl;
			alcDestroyContext(context);
			alcCloseDevice(device);
			return;
		}

		ALuint buffer;
		alGenBuffers(1, &buffer);
	/*	if (alGetError() != AL_NO_ERROR) {
			std::cerr << "Failed to generate OpenAL buffer" << std::endl;
			alcMakeContextCurrent(nullptr);
			alcDestroyContext(context);
			alcCloseDevice(device);
			return;
		}*/

		ALenum error = alGetError();
		if (error != AL_NO_ERROR)
		{
			std::cerr << "***ERROR***\n";
			switch (error)
			{
			case AL_INVALID_NAME:
				std::cerr << "AL_INVALID_NAME: a bad name (ID) was passed to an OpenAL function";
				break;
			case AL_INVALID_ENUM:
				std::cerr << "AL_INVALID_ENUM: an invalid enum value was passed to an OpenAL function";
				break;
			case AL_INVALID_VALUE:
				std::cerr << "AL_INVALID_VALUE: an invalid value was passed to an OpenAL function";
				break;
			case AL_INVALID_OPERATION:
				std::cerr << "AL_INVALID_OPERATION: the requested operation is not valid";
				break;
			case AL_OUT_OF_MEMORY:
				std::cerr << "AL_OUT_OF_MEMORY: the requested operation resulted in OpenAL running out of memory";
				break;
			default:
				std::cerr << "UNKNOWN AL ERROR: " << error;
			}
			std::cerr << std::endl;
			alcMakeContextCurrent(nullptr);
			alcDestroyContext(context);
			alcCloseDevice(device);
			isPlaying = false;
			return;

		}

		ALenum format;
		ALsizei size, freq;
		ALvoid* data;

		ReadWavData monoData = Sound::GetWavData(filename);

		alBufferData(buffer, monoData.channels > 1 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, monoData.pcmData.data(), monoData.pcmData.size() * 2 /*two bytes per sample*/, monoData.sampleRate);

		ALuint source;
		alGenSources(1, &source);
		alSourcei(source, AL_BUFFER, buffer);

		alSourcePlay(source);

		ALint state;
		do {
			isRunning = true;
			alGetSourcei(source, AL_SOURCE_STATE, &state);
		} while (state == AL_PLAYING);
		isRunning = false;

		alDeleteSources(1, &source);
		alDeleteBuffers(1, &buffer);

		alcMakeContextCurrent(nullptr);
		alcDestroyContext(context);
		alcCloseDevice(device);
		isPlaying = false;
	}


}