#pragma once
#include <alc.h>
#include <al.h>

namespace Latno
{
	
	class SoundDevice
	{
	public:
		static SoundDevice* get();
		static void PlaySound();
		static void Play(ALuint audio);
	private:
		SoundDevice();
		~SoundDevice();

		ALCdevice* p_ALCDevice;
		ALCcontext* p_ALCContext;

	};
}