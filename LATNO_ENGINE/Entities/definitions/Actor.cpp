#pragma once

#include "../declarations/Actor.h"

namespace Latno 
{
	Actor::Actor(float _x, float _y, std::string SpritePath)
	{
		position = Coords(_x, _y);
		sprite = new Sprite(glm::vec3(_x, _y, 0), glm::vec2(1.0f, 1.0f), SpritePath);
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();

		collisionBox = new CollisionBox(position, { 50 * scale.x * SpriteRatio, 50 * scale.y }, "AABB");
		
		preData = position;
	}

	Actor::Actor(float _x, float _y, std::string SpritePath, std::string collisionType)
	{
		
		
		position = Coords(_x, _y);
		sprite = new Sprite(glm::vec3(_x, _y, 0), glm::vec2(1.0f, 1.0f), SpritePath);
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();
		if (collisionType == "AABD")
			collisionBox = new CollisionBox(position, { 50 * scale.x * SpriteRatio, 50 * scale.y }, "AABB");
		else if (collisionType == "RADIUS")
			collisionBox = new CollisionBox(position, { 75 * scale.x * SpriteRatio, 75 * scale.y }, "RADIUS"); //NEED TO DETERMINE TRUE SPRITE SIZE AND NOT JUST  75
		preData = position;
		
	}

	Actor::Actor(float _x, float _y, glm::vec2 _scale, std::string SpritePath)
	{
		position = Coords(_x, _y);
		scale = _scale;
		
		sprite = new Sprite(glm::vec3(_x, _y, 0), scale, SpritePath);
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();

		collisionBox = new CollisionBox(position, { 50 * scale.x * SpriteRatio, 50 * scale.y }, "AABB");


		preData = position;
	}

	Actor::Actor(Coords _Pos, std::string SpritePath)
	{
		position = _Pos;
		sprite = new Sprite(glm::vec3(_Pos.x, _Pos.y, 0), glm::vec2(1.0f, 1.0f), SpritePath);
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();

		collisionBox = new CollisionBox(position, { 50 * SpriteRatio, 50 }, "AABB");


		preData = _Pos;
	}
	Actor::Actor(Coords _Pos, glm::vec2 _scale, std::string SpritePath)
	{
		position = _Pos;
		scale = _scale;

		sprite = new Sprite(glm::vec3(_Pos.x, _Pos.y, 0), scale, SpritePath);
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();

		collisionBox = new CollisionBox(position, { 50 * scale.x * SpriteRatio, 50 * scale.y }, "AABB");


		preData = position;
	}

	Actor::Actor()
	{
		position = Coords{0,0};
	}

	void Actor::SendBack()
	{
		SetPos(preData);
	}

	bool Actor::CheckCollision(Actor actor) const
	{
		return collisionBox->CheckCollision(*actor.collisionBox);
	}
	bool Actor::CheckCollision(Coords point) const
	{
		return collisionBox->CheckCollision(point);
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
		collisionBox->size.x = 50 * scale.x * SpriteRatio;
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
		SpriteRatio = (float)sprite->texture->GetWidth() / sprite->texture->GetHeight();
		SetScale(GetScale()); // Updates collisionBox scaling
	}

	void Actor::Animate(float timeBetweenFrames, std::vector<std::string>& spriteList)
	{
		animSwapTime += 1 * GLOBAL_DELTA_TIME;
		if (animSwapTime >= timeBetweenFrames)
		{
			animSwapTime = 0;

			if (animIndex >= spriteList.size())
				animIndex = 0;

			SwapTexture(spriteList[animIndex++]);
		}
	}
}