#pragma once

#include "../declarations/Actor.h"

namespace Latno_Entities 
{
	Actor::Actor(int _x, int _y, std::string SpritePath, std::string _name)
	{
		position.x = _x;
		position.y = _y;
		//sprite = std::make_unique<Sprite>(glm::vec3(position.x, position.y, 0), glm::vec2(1.0f, 1.0f), SpritePath, "AABB");
		sprite = new Sprite(glm::vec3(_x, _y, 0), glm::vec2(1.0f, 1.0f), SpritePath, "AABB");

		size.x = 50 * scale.x;
		size.y = 50 * scale.y;
		collisionBox = new CollisionBox(position, size, "AABB");
		collisionBox->size.x = 50 * scale.x;
		collisionBox->size.y = 50 * scale.y;
		
		
		name = _name;
		preData.x = _x;
		preData.y = _y;
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
		SetPos(GetPos());
	}

	Actor::Actor(int _x, int _y, glm::vec2 _scale, std::string SpritePath, std::string _name, std::string _enum)
	{
		position.x = _x;
		position.y = _y;
		scale = _scale;
		

		
		
		//sprite = std::make_unique<Sprite>(glm::vec3(position.x, position.y, 0), glm::vec2(1.0f, 1.0f), SpritePath, "AABB");
		sprite = new Sprite(glm::vec3(_x, _y, 0), scale, SpritePath, _enum);

		size.x = 50 * scale.x;
		size.y = 50 * scale.y;
		collisionBox = new CollisionBox(position, size, "AABB");

		collisionBox->size.x = 50 * _scale.x;
		collisionBox->size.y = 50 * _scale.y;

		name = _name;
		preData.x = _x;
		preData.y = _y;
		SetPos(GetPos());
	}

	Actor::Actor(Coords _Pos, std::string SpritePath, std::string _name)
	{
		position = _Pos;
		sprite = new Sprite(glm::vec3(_Pos.x, _Pos.y, 0), glm::vec2(1.0f, 1.0f), SpritePath, "AABB");

		name = _name;
		preData = _Pos;
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
		SetPos(GetPos());
	}

	Actor::Actor()
	{
		position = {0,0};
		name = "UN-NAMED_ACTOR";
		//LOGLN("Actor named \"" + name + "\" was succesfully created with the coords: (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")");
	}

	void Actor::SetCoords(int x,int y)
	{
		preData = position;
		position.x = x;
		position.y = y;
	}

	void Actor::SetCoords(Coords Pos)
	{
		preData = position;
		position = Pos;
	}

	bool Actor::CheckCollision(Actor Actor) const
	{
		if(position.IsEqual(Actor.position))
			return true;
		return false;
	}

	bool Actor::CheckCollision(Coords Point) const
	{
		if(position.IsEqual(Point))
			return true;
		return false;
	}

	bool Actor::IsNearby(Actor Actor) const
	{
		int AX = Actor.position.x,
				AY = Actor.position.y,
				X = position.x,
				Y = position.y;
		if((AX == X || AX == X - 1 || AX == X + 1) && (AY == Y || AY == Y - 1 || AY == Y + 1))
			return true;
		return false;
	}

	bool Actor::IsNearby(Coords Point) const
	{
		int AX = Point.x,
				AY = Point.y,
				X = position.x,
				Y = position.y;
		if((AX == X || AX == X - 1 || AX == X + 1) && (AY == Y || AY == Y - 1 || AY == Y + 1))
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
		collisionBox->topLeft = { position.x - size.x / 2, position.y + size.y / 2 };
		collisionBox->botRight = { position.x + size.x / 2, position.y - size.y / 2 };
		
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
