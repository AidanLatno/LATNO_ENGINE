#include "../declarations/TextRenderer.h"

namespace Latno
{
	Actor TextRenderer::GetLetterActor(char letter)
	{
		switch (letter)
		{
		case 'A':
			return Actor({ 0,0 }, "resources/textures/text/A.png");
		case 'B':
			return Actor({ 0,0 }, "resources/textures/text/B.png");
		case 'C':
			return Actor({ 0,0 }, "resources/textures/text/C.png");
		case 'D':
			return Actor({ 0,0 }, "resources/textures/text/D.png");
		case 'E':
			return Actor({ 0,0 }, "resources/textures/text/E.png");
		case 'F':
			return Actor({ 0,0 }, "resources/textures/text/F.png");
		case 'G':
			return Actor({ 0,0 }, "resources/textures/text/G.png");
		case 'H':
			return Actor({ 0,0 }, "resources/textures/text/H.png");
		case 'I':
			return Actor({ 0,0 }, "resources/textures/text/I.png");
		case 'J':
			return Actor({ 0,0 }, "resources/textures/text/J.png");
		case 'K':
			return Actor({ 0,0 }, "resources/textures/text/K.png");
		case 'L':
			return Actor({ 0,0 }, "resources/textures/text/L.png");
		case 'M':
			return Actor({ 0,0 }, "resources/textures/text/M.png");
		case 'N':
			return Actor({ 0,0 }, "resources/textures/text/N.png");
		case 'O':
			return Actor({ 0,0 }, "resources/textures/text/O.png");
		case 'P':
			return Actor({ 0,0 }, "resources/textures/text/P.png");
		case 'Q':
			return Actor({ 0,0 }, "resources/textures/text/Q.png");
		case 'R':
			return Actor({ 0,0 }, "resources/textures/text/R.png");
		case 'S':
			return Actor({ 0,0 }, "resources/textures/text/S.png");
		case 'T':
			return Actor({ 0,0 }, "resources/textures/text/T.png");
		case 'U':
			return Actor({ 0,0 }, "resources/textures/text/U.png");
		case 'V':
			return Actor({ 0,0 }, "resources/textures/text/V.png");
		case 'W':
			return Actor({ 0,0 }, "resources/textures/text/W.png");
		case 'X':
			return Actor({ 0,0 }, "resources/textures/text/X.png");
		case 'Y':
			return Actor({ 0,0 }, "resources/textures/text/Y.png");
		case 'Z':
			return Actor({ 0,0 }, "resources/textures/text/Z.png");
		case '0':
			return Actor({ 0,0 }, "resources/textures/text/0.png");
		case '1':
			return Actor({ 0,0 }, "resources/textures/text/1.png");
		case '2':
			return Actor({ 0,0 }, "resources/textures/text/2.png");
		case '3':
			return Actor({ 0,0 }, "resources/textures/text/3.png");
		case '4':
			return Actor({ 0,0 }, "resources/textures/text/4.png");
		case '5':
			return Actor({ 0,0 }, "resources/textures/text/5.png");
		case '6':
			return Actor({ 0,0 }, "resources/textures/text/6.png");
		case '7':
			return Actor({ 0,0 }, "resources/textures/text/7.png");
		case '8':
			return Actor({ 0,0 }, "resources/textures/text/8.png");
		case '9':
			return Actor({ 0,0 }, "resources/textures/text/9.png");
		case ':':
			return Actor({ 0,0 }, "resources/textures/text/colon.png");
		case '?':
			return Actor({ 0,0 }, "resources/textures/text/question.png");
		case '!':
			return Actor({ 0,0 }, "resources/textures/text/!.png");
		case ' ':
			return Actor({ 0,0 }, "");

		default:
			return Actor({ 0,0 }, "resources/textures/text/question.png");
		}
	}

	void TextRenderer::AddText(std::string text, std::string textBoxName, Scene* scene, Coords startPos, int length, float letterSize)
	{
		std::vector<Actor> textActors;
		int maxPos = startPos.x + length;

		for (char c : text)
		{
			textActors.push_back(GetLetterActor(c));
			textActors[textActors.size() - 1].AddTag(textBoxName);
			textActors[textActors.size() - 1].AddTag("text");
			textActors[textActors.size() - 1].AddTag(std::to_string(c));
			textActors[textActors.size() - 1].SetScale({letterSize,letterSize});
		}

		int line = 0;
		int count = 0;

		for (int i = 0; i < textActors.size(); i++)
		{
			if ((count * (77 * letterSize)) >= length)
			{
				line++;
				count = 0;
			}

			textActors[i].SetPos(Coords( startPos.x + (count*(77*letterSize)), startPos.y - (line * (77 * letterSize))));

			scene->AddDynamicActor(textActors[i]);
			
			count++;
		}

	}

	void TextRenderer::RemoveText(std::string textBoxName, Scene* scene)
	{
		for (int i = 0; i < scene->dynamicActors.size(); i++)
		{
			if (scene->dynamicActors[i].IfHasTag(textBoxName))
			{
				scene->DestroyDynamicActor(i);
				i--;
			}
		}
	}
	void TextRenderer::Clear(Scene* scene)
	{
		for (int i = 0; i < scene->dynamicActors.size(); i++)
		{
			if (scene->dynamicActors[i].IfHasTag("text"))
			{
				scene->DestroyDynamicActor(i);
				i--;
			}
		}
	}
}