#pragma once
#include "../../Entities/declarations/Pathfinder.h"

namespace Latno
{
	class TextRenderer
	{
	private:
		static Actor GetLetterActor(char letter);

	public:
		static void AddText(std::string text, std::string textBoxName, Scene* scene, Coords startPos, int length, float letterSize = 1.0f);
		static void RemoveText(std::string textBoxName, Scene* scene);
		static void Clear(Scene* scene);


	};
}