#pragma once

#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Models/shader.h"
#include "ECS.h"


class Camera : public Component
{
public:
    unsigned int SCR_WIDTH, SCR_HEIGHT;
    void Camera_render(Shader shader);
    // glfw: whenever the mouse scroll wheel scrolls, this callback is called
    // ----------------------------------------------------------------------
    // camera
    glm::vec3 cameraPos{ glm::vec3(0.0f, 0.0f, 3.0f) };
    glm::vec3 cameraFront{ glm::vec3(0.0f, 0.0f, -1.0f) };
    glm::vec3 cameraUp{ glm::vec3(0.0f, 1.0f, 0.0f) };

    
    float fov{90.0f};
};
