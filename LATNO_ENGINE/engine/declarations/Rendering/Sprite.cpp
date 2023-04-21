#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, Texture _texture, std::string _enum)
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

	if (_enum == "AABB")
		collisiontype = CollisionType::AABB;
	else if(_enum == "circ")
		collisiontype = CollisionType::CIRCULAR;
}
Sprite::Sprite(glm::vec3 _position, glm::vec2 _scale, std::string _texture, std::string _enum)
{
	texture = std::make_unique<Texture>(_texture);
	shader = std::make_unique<Shader>("resources/shaders/Basic.shader");

	Position = _position;
	Scale = _scale;

	if (_enum == "AABB")
		collisiontype = CollisionType::AABB;
	else if (_enum == "circ")
		collisiontype = CollisionType::CIRCULAR;
}

bool Sprite::CheckCollisions(Sprite sprite2)
{
	if (collisiontype == CollisionType::AABB) 
	{
		bool x = this->Position.x + this->Size.x >= sprite2.Position.x && sprite2.Position.x + sprite2.Size.x >= sprite2.Position.x;
		bool y = this->Position.y + this->Size.y >= sprite2.Position.y && sprite2.Position.y + sprite2.Size.y >= this->Position.y;
		return x && y;
	}

	if (collisiontype == CollisionType::CIRCULAR)
	{

		glm::vec2 center(this->Position.x + this->Radius, this->Position.y + this->Radius);
		glm::vec2 half(sprite2.Size.x / 2.0f, sprite2.Size.y / 2.0f);
		glm::vec2 AABBCenter(sprite2.Position.x + half.x, sprite2.Position.y + half.y);
		glm::vec2 difference = center - AABBCenter;
		glm::vec2 clamp = glm::clamp(difference, -half, half);
		glm::vec2 closest = AABBCenter + clamp;
		difference = closest - center;
		return glm::length(difference) < this->Radius;
	}
	
}

