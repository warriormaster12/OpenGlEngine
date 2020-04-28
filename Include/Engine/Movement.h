 #pragma once 

#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ECS.h"


class Movement : public Component
{
public: 
    GLFWwindow *window;
    void processInput(float deltaTime);
    void Process_Mouse_Movement(float xpos,float ypos);
    void update(double Delta) override; 

    glm::vec3 Pos{ glm::vec3(0.0f, 0.0f, 3.0f) };
    glm::vec3 Front{ glm::vec3(0.0f, 0.0f, -1.0f) };
    glm::vec3 Up{ glm::vec3(0.0f, 1.0f, 0.0f) };

    bool firstMouse{true};
    float yaw{-90.0f};	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float pitch{0.0f};
    float lastX{800.0f / 2.0};
    float lastY{600.0 / 2.0};

};