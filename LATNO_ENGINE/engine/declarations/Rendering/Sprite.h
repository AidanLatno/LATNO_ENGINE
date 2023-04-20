#pragma once

#include "Shader.h"
#include "Texture.h"

class Sprite
{
private:
    Texture texture;
    glm::vec2 Position;
    float Rotation;
    glm::vec2 Scale;

public:
    Sprite(glm::vec2 _position, glm::vec2 _scale, Texture _texture);
};