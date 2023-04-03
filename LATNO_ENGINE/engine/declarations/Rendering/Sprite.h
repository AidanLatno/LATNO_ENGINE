#pragma once

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"




class Sprite
{
private:
    std::string file;
    float vertices[];
    
public:
    Sprite(std::string file, glm::vec3 position, glm::vec2 scale);
};