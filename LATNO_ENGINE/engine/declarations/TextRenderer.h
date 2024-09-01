#pragma once
#include "../../Entities/declarations/Pathfinder.h"

namespace Latno
{
	enum Alignment
	{
		LEFT_ALIGN = -1,
		CENTER_ALIGN = 0,
		RIGHT_ALIGN = 1
	};

	class TextRenderer
	{
	private:
		static Actor GetLetterActor(char letter);

	public:
		static void AddText(std::string text, std::string textBoxName, Scene* scene, Coords startPos, int length, float letterSize = 1.0f, Alignment alignment = LEFT_ALIGN);
		static void RemoveText(std::string textBoxName, Scene* scene);
		static void Clear(Scene* scene);


	};
}