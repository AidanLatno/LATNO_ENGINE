#include "engine/declarations/Rendering/Shader.h"
#include "engine/declarations/Rendering/Texture.h"
#include "engine/declarations/Rendering/VertexBuffer.h"
#include "engine/declarations/Rendering/VertexBufferLayout.h"
#include "engine/declarations/Rendering/VertexArray.h"




class Sprite
{


private:
    Shader shader;

    VertexArray objectArray;

    void initRenderData();

public:
    Sprite(Shader &shader);
    ~Sprite();

    void DrawSprite(Texture &texture, glm::vec2 position,
        glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
        glm::vec3 color = glm::vec3(1.0f));

};