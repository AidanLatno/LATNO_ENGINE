#pragma once
#include "InputManager.h"

namespace Latno
{

	struct ReadWavData;

	class Sound {
	public:
		std::string filename;
		bool isPlaying = false;
		bool isRunning = false;
		static std::string s_filename;

		Sound(std::string filename) : filename(filename) {}


		~Sound() {
			// Make sure to stop the audio thread before destroying the AudioManager
			if (audioThread.joinable()) {
				audioThread.join();
			}
		}

		void play();

	private:
		
		std::thread audioThread;

		static ReadWavData GetWavData(std::string file);

		void playAudioFile();
	};
}