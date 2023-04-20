#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, Texture _texture)
{
	texture = std::make_unique<Texture>(_texture.GetPath());
	shader = std::make_unique<Shader>("resources/shaders/Basic.shader");

	Position = _position;
	Scale = _scale;
}
Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, std::string _texture)
{
	texture = std::make_unique<Texture>(_texture);
	shader = std::make_unique<Shader>("resources/shaders/Basic.shader");

	Position = _position;
	Scale = _scale;
}

