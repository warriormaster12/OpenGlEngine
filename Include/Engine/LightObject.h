#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>
#include "shader_s.h"
#include "Camera.h"

class point_light
{
public: 
   // lighting
    glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
    void create_light(Shader shader, unsigned int VBO, unsigned int VAO);
    void render_light(Shader shader, unsigned int VBO, unsigned int VAO);
    
    void Delete_Object(unsigned int VBO, unsigned int VAO);
    
private: 
    Camera camera;
};
