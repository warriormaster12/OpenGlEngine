#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int SCR_WIDTH{1920};
const unsigned int SCR_HEIGHT{1080};
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window, float deltaTime);


class InitWindow {
public:
    GLFWwindow* window;
    InitWindow();
};
