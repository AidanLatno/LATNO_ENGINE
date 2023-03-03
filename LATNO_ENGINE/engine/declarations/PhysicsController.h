#pragma once
#include "Scene.h"


class PhysicsController : public Latno::Component
{
	Latno_Entities::Actor* attachedActor;
	Scene* mainScene;

	void UpdateInfo();

	void ApplyGravity();


};