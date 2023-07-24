#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, Texture _texture)
{
	texture = std::make_unique<Texture>(_texture.GetPath());
	shader = std::make_unique<Shader>("resources/shaders/Basic.shader");

	Position = _position;
	Scale = _scale;
	Size = _texture.GetSize();

	if (Size.x >= Size.y)
		Radius = Size.x / 2;
	else if (Size.y >= Size.x)
		Radius = Size.y / 2;

}
Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, std::string path)
{
	texture = std::make_unique<Texture>(path);
	shader = std::make_unique<Shader>("resources/shaders/Basic.shader");

	Position = _position;
	Scale = _scale;

}
