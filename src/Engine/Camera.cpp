#include "Engine/Camera.h"

void Camera::Process_Mouse_Scroll(float yoffset) {
    if (fov >= 90.0f && fov <= 120.0f)
        fov -= yoffset;
    if (fov <= 90.0f)
        fov = 90.0f;
    if (fov >= 120.0f)
        fov = 120.0f;
}

void Camera::Camera_render(Shader shader) {
         // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        shader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        shader.setMat4("view", view);
}

