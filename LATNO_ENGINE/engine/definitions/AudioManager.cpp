#include "../declarations/AudioManager.h"

#include "dr_wav/dr_wav.h"

struct ReadWavData
{
	unsigned int channels = 0;
	unsigned int sampleRate = 0;
	drwav_uint64 totalPCMFrameCount = 0;
	std::vector<uint16_t> pcmData;
	drwav_uint64 getTotalSamples() { return totalPCMFrameCount * channels; }
};

#define DR_WAV_IMPLEMENTATION

std::string AudioManager::s_filename;

void AudioManager::play() {
	audioThread = std::thread([this]() {
		playAudioFile();
		});
}


ReadWavData AudioManager::GetWavData(std::string file)
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

void AudioManager::playAudioFile()
{
	ALCdevice* device = alcOpenDevice(nullptr);
	if (!device) {
		std::cerr << "Failed to initialize OpenAL device" << std::endl;
		return;
	}

	ALCcontext* context = alcCreateContext(device, nullptr);
	alcMakeContextCurrent(context);

	ALuint buffer;
	alGenBuffers(1, &buffer);

	ALenum format;
	ALsizei size, freq;
	ALvoid* data;

	ReadWavData monoData = AudioManager::GetWavData(filename);

	alBufferData(buffer, monoData.channels > 1 ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16, monoData.pcmData.data(), monoData.pcmData.size() * 2 /*two bytes per sample*/, monoData.sampleRate);

	ALuint source;
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);

	alSourcePlay(source);

	ALint state;
	do {
		alGetSourcei(source, AL_SOURCE_STATE, &state);
	} while (state == AL_PLAYING);

	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);

	alcMakeContextCurrent(nullptr);
	alcDestroyContext(context);
	alcCloseDevice(device);
}