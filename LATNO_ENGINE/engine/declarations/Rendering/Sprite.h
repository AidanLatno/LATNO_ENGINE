#pragma once

#include "engine/declarations/Rendering/Shader.h"
#include "engine/declarations/Rendering/Texture.h"
#include "engine/declarations/Rendering/VertexBuffer.h"
#include "engine/declarations/Rendering/VertexBufferLayout.h"
#include "engine/declarations/Rendering/VertexArray.h"




class Sprite
{
private:
    String file;
    float[] vertices;
    
public:
    Sprite(String file, glm::vec3 position, glm::vec2 scale);
};