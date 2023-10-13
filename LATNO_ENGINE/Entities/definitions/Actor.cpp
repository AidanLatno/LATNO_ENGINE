#pragma once

#include "../declarations/Actor.h"

namespace Latno 
{
	Actor::Actor(float _x, float _y, std::string SpritePath)
	{
		position = Coords(_x, _y);
		sprite = new Sprite(glm::vec3(_x, _y, 0), glm::vec2(1.0f, 1.0f), SpritePath);

		collisionBox = new CollisionBox(position, { 50 * scale.x, 50 * scale.y }, "AABB");
		
		preData = position;
		SetPos(GetPos()); // No clue why but this fixes things, DONT DELETE
	}

	Actor::Actor(float _x, float _y, glm::vec2 _scale, std::string SpritePath)
	{
		position = Coords(_x, _y);
		scale = _scale;
		
		sprite = new Sprite(glm::vec3(_x, _y, 0), scale, SpritePath);

		collisionBox = new CollisionBox(position, { 50 * scale.x, 50 * scale.y }, "AABB");


		preData = position;
		SetPos(GetPos()); // No clue why but this fixes things, DONT DELETE
	}

	Actor::Actor(Coords _Pos, std::string SpritePath)
	{
		position = _Pos;
		sprite = new Sprite(glm::vec3(_Pos.x, _Pos.y, 0), glm::vec2(1.0f, 1.0f), SpritePath);
		collisionBox = new CollisionBox(position, { 50, 50 }, "AABB");


		preData = _Pos;
		SetPos(GetPos()); // No clue why but this fixes things, DONT DELETE
	}

	Actor::Actor()
	{
		position = Coords{0,0};
	}

	bool Actor::CheckCollision(Actor Actor) const
	{
		if(collisionBox->CheckCollision(*Actor.collisionBox))
			return true;
		return false;
	}
	bool Actor::CheckCollision(Coords point) const
	{
		if (collisionBox->CheckCollision(point))
			return true;
		return false;
	}

	Coords Actor::GetPos() const
	{
		return position;
	}

	void Actor::SetPos(Coords _pos)
	{
		position = _pos;
		sprite->Position = glm::vec3(position.x, position.y, 0);
		collisionBox->position = _pos;
		collisionBox->topLeft = { position.x - collisionBox->size.x / 2, position.y + collisionBox->size.y / 2 };
		collisionBox->botRight = { position.x + collisionBox->size.x / 2, position.y - collisionBox->size.y / 2 };
		
	}

	void Actor::SetSpriteScale(float x, float y)
	{
		sprite->Scale = glm::vec2(x, y);
	}
	void Actor::SetCollisionSize(glm::vec2 scale)
	{
		collisionBox->size.x = 50 * scale.x;
		collisionBox->size.y = 50 * scale.y;
	}
	
	glm::vec2 Actor::GetScale()
	{
		return scale;
	}
	void Actor::SetScale(glm::vec2 _scale)
	{
		scale = _scale; 
		SetSpriteScale(scale.x,scale.y);
		SetCollisionSize(scale);
	}

	void Actor::SwapTexture(std::string path)
	{
		sprite->texture.reset();
		sprite->texture = std::make_unique<Texture>(path);
	}
	
}

// preData