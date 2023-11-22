#pragma once
#include "InputManager.h"

struct ReadWavData;

class AudioManager {
public:
	static std::string s_filename;

	AudioManager(std::string filename) : filename(filename) {}


	~AudioManager() {
		// Make sure to stop the audio thread before destroying the AudioManager
		if (audioThread.joinable()) {
			audioThread.join();
		}
	}

	void play();
	static void play(std::string file) {
		s_filename = file;
		std::thread audioThread = std::thread([]() {
			AudioManager manager(s_filename);
			std::cout << s_filename;
			manager.playAudioFile();
			});
	}

private:
	std::string filename;
	std::thread audioThread;

	static ReadWavData GetWavData(std::string file);

	void playAudioFile();
};