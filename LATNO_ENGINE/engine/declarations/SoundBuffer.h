#pragma once
#include <al.h>
#include <vector>

namespace Latno
{
	class SoundBuffer
	{
	public:
		static SoundBuffer* get();

		ALuint addSoundEffect(const char* filename);
		bool removeSoundEffect(const ALuint& buffer);

	private:
		SoundBuffer();
		~SoundBuffer();

		std::vector<ALuint> p_SoundEffectBuffers;
	};
}