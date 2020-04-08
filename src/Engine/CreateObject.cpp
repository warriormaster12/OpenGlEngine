#include "../Include/Engine/CreateObject.h"
  
void Object::Render_Object()
{
        model_shader.use();
        glm::mat4 model = glm::mat4(scale);
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
        model_shader.setMat4("model", model);
}