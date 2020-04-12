#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>
#include "../Models/shader.h"


class Object
{
public:
    Object();
    void Render_Object();
    // world space positions of our object
    glm::vec3 WorldPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(0.01f,0.01f,0.01f);
    std::string model_directory = "assets/Models/chapel/chapel_obj.obj";
    Shader model_shader = Shader("assets/Shaders/model_loading.vs", "assets/Shaders/model_loading.fs");
};
