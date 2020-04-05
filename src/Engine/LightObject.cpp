#include "Engine/LightObject.h"
point_light::point_light()
{
    Object();
}
void point_light::render_light(Shader shader) {
    shader.use();
    model = glm::mat4(1.0f);
    model = glm::translate(model, WorldPos);
    model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

}

point_light::~point_light() {
    //TODO: Move this to deconstructor
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
