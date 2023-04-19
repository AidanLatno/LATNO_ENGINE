#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Sprite::Sprite(glm::vec2 _position, glm::vec2 _scale, Texture _texture)
{
	texture = _texture;
}

