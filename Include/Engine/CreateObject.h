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

class Object
{
public:     
    void Create_Object(Shader shader, unsigned int VBO, unsigned int VAO);
    
    
    void Render_Object(Shader shader, unsigned int VBO, unsigned int VAO);
    
    void Delete_Object(unsigned int VBO, unsigned int VAO);
    
private: 
    unsigned int texture1, texture2;
    void create_textures(Shader shader);    
};
