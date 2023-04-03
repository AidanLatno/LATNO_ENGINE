#include "Sprite.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Sprite::Sprite(String file, glm::vec3 position, glm::vec2 scale) {
    this->vertices = {
        //do math
		-50.0f, -50.0f, 0.0f, 0.0f, // 0 - bottom left
		50.0f, -50.0f, 1.0f, 0.0f, // 1 - bottom right
		50.0f, 50.0f, 1.0f, 1.0f, // 2 - top right
		-50.0f, 50.0f, 0.0f, 1.0f // 3 - top left
	};

    this -> file = file;
}

