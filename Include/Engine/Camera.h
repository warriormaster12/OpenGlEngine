#pragma once

#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Models/shader.h"


class Camera
{
public:
    unsigned int SCR_WIDTH, SCR_HEIGHT;
    void processInput(GLFWwindow *window, float deltaTime);
    void Process_Mouse_Movement(float xpos,float ypos);


    // glfw: whenever the mouse scroll wheel scrolls, this callback is called
    // ----------------------------------------------------------------------
    void Process_Mouse_Scroll(float yoffset);

    void Camera_render(Shader shader);

private: 
    // camera
    glm::vec3 cameraPos{ glm::vec3(0.0f, 0.0f, 3.0f) };
    glm::vec3 cameraFront{ glm::vec3(0.0f, 0.0f, -1.0f) };
    glm::vec3 cameraUp{ glm::vec3(0.0f, 1.0f, 0.0f) };

    bool firstMouse{true};
    float yaw{-90.0f};	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float pitch{0.0f};
    float lastX{800.0f / 2.0};
    float lastY{600.0 / 2.0};
    float fov{90.0f};
};
