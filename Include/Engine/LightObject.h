#pragma once

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
