#pragma once
#include "../../engine/declarations/Application.h"

using namespace Latno; // Not neccesary but makes it easier


/*
*/
class ExampleApp : public Application
{
public:
	// Level refs
	Scene* level;

	// Actor refs
	SpawnActorButton* button;
	PlayerExample* player;

	// Tool Refs
	Pathfinder* pathFind;
	PhysicsController* physics;

	// Loaded Audio Files
	ALuint pacman_dead = SoundBuffer::get()->addSoundEffect("resources/audio/pacman_dies.wav");
	ALuint pacman_intro = SoundBuffer::get()->addSoundEffect("resources/audio/pacman_intro.wav");
	ALuint opening_music = SoundBuffer::get()->addSoundEffect("resources/audio/credits-opening1.ogg");
	ALuint canary = SoundBuffer::get()->addSoundEffect("resources/audio/canary.wav");

	void Load() override;
	bool Tick() override;
	void End() override;
	void FixedTick() override;

	int count = 0;
	float average = 0;
	float fps = 0;
};