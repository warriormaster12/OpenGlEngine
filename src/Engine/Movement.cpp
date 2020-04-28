#include "Engine/Movement.h"

void Movement::processInput(float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float Speed = 5.0;
    Speed = Speed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        Pos += Speed * Front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        Pos -= Speed * Front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        Pos -= glm::normalize(glm::cross(Front, Up)) * Speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        Pos += glm::normalize(glm::cross(Front, Up)) * Speed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        Pos += Speed * Up;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        Pos -= Speed * Up;
}

void Movement::Process_Mouse_Movement(float xpos, float ypos) {
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    Front = glm::normalize(front);
}
void Movement::Process_Mouse_Scroll(float yoffset) {
    if (axis_scale >= 90.0f && axis_scale <= 120.0f)
        axis_scale -= yoffset;
    if (axis_scale <= 90.0f)
        axis_scale = 90.0f;
    if (axis_scale >= 120.0f)
        axis_scale = 120.0f;
}

void Movement::update(double Delta)
{
    processInput(Delta);
}