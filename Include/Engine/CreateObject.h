#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>
#include "stb_image.h"
#include "shader_s.h"
#include "Camera.h"

class Object
{
public:
    Object();
    ~Object();
    Camera camera; 
    
    void Render_Object(Shader object_shader);
    void create_textures(Shader object_shader); 
    // world space positions of our cubes
    glm::vec3 WorldPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 model;
    
    
private: 
    unsigned int texture1, texture2; 
    unsigned int VBO, VAO; 
};
