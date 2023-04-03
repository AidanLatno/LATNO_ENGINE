#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

void Sprite::initRenderData()
{
    float vertices[] = {

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    //me no understand

    objectArray;// IMPORTANT DONT REMOVE

    objectArray = VertexArray();
    
    /*glGenVertexArrays(1, &this->objectArray);*/

    VertexBuffer vertexData(vertices, sizeof(vertices));
    /*glGenBuffers(1, &vertexData);
    glBindBuffer(GL_ARRAY_BUFFER, vertexData);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);*/

    objectArray.Bind();
    //glBindVertexArray(this->objectArray);

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);

    objectArray.AddBuffer(vertexData, layout);
    /*glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);*/

    vertexData.Unbind();
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    objectArray.Unbind();
    //glBindVertexArray(0);
}

void Sprite::DrawSprite(Texture& texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{

    shader.Bind();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    this->shader.SetUniformMat4f("model", model);
    this->shader.SetUniform3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    objectArray.Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
    objectArray.Unbind();

}