#pragma once

#include "Shader.h"
#include "Texture.h"

class Sprite
{
private:
    
public:
    std::unique_ptr<Texture> texture;
    std::unique_ptr<Shader> shader;
    glm::vec3 Position;
    float Rotation;
    glm::vec2 Scale;

    Sprite(glm::vec3 _position, glm::vec2 _scale, Texture _texture, std::string _enum);
    Sprite(glm::vec3 _position, glm::vec2 _scale, std::string path, std::string _enum);


    // Deep collision
    glm::vec2 Size;
    unsigned int Radius;
 
    enum CollisionType
    {
        AABB,
        CIRCULAR
    };
    CollisionType collisiontype;
    
    bool CheckCollisions(Sprite sprite2);
};