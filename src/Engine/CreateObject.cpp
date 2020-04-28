#include "../Include/Engine/CreateObject.h"

void Object::begin_play()
{
        WorldPos = glm::vec3(0.0f, -1.75f, 0.0f);
}


void Object::render()
{
        model_shader.use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(WorldPos)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));	// it's a bit too big for our scene, so scale it down
        model_shader.setMat4("model", model);
}