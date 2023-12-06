#pragma once
#include "Sound.h"
namespace Latno
{
	class AudioManager : public Component
	{
	private:
		
	public:
		int frameCount = 0;
		std::vector<Sound*> sounds;
		~AudioManager();

		void PlayWavFile(std::string filePath);

		void Update() override;

	};
}