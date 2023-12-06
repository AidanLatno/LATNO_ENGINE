#include "../declarations/AudioManager.h"
namespace Latno
{
	AudioManager::~AudioManager()
	{
		for (Sound*& s : sounds)
		{
			delete s;
		}
	}

	void AudioManager::PlayWavFile(std::string filePath)
	{
		sounds.push_back(new Sound(filePath));
		sounds[sounds.size() - 1]->play();
	}

	void AudioManager::Update()
	{
		if (frameCount == 165)
		{
			frameCount = 0;
			for (int i = 0; i < sounds.size(); i++)
			{
				if (!sounds[i]->isPlaying)
				{
					delete sounds[i];
					sounds.erase(sounds.begin() + i);
				}
			}
		}
		frameCount++;
	}
}