#pragma once 

#include "ECS.h"

class PositionComponent : public Component 
{
private: 
    int xpos; 
    int ypos;
public: 

    int x() {return xpos; }
    int y() {return ypos; }

    void begin_play() override
    {
        xpos = 0;
        ypos = 0;
    }
    void update(double Delta) override
    {
        xpos++*Delta;
        ypos++*Delta;
    }
    void setPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
};