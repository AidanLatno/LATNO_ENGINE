#include "../declarations/Shader.h"
#include "../declarations/Texture.h"
#include "../declarations/VertexBuffer.h"
#include "../declarations/VertexBufferLayout.h"
#include "../declarations/VertexArray.h"

class Sprite
{

private:
    Shader shader;

    VertexArray objectArray;

    void initRenderData();

public:
    Sprite(Shader& shader);

    //~Sprite();

    void DrawSprite(Texture& texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));

};