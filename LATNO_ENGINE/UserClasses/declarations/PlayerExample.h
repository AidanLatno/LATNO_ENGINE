#pragma once
#include "../../engine/declarations/Application.h"

class PlayerExample : public Latno::PlayerBase
{
	using PlayerBase::PlayerBase;

public:
	std::vector<std::string> spriteList;
	void Update() override;
	void Start() override;

};