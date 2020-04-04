#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>
#include "shader_s.h"
#include "CreateObject.h"

class point_light : public Object
{
public: 
   // lighting
    point_light();
    void render_light(Shader shader);
    
    ~point_light();
    
private: 
    unsigned int VBO, VAO;
};
