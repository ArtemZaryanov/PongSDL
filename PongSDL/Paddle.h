#pragma once
#include "Entity.h"
class Paddle :
    public Entity
{
public:
    Paddle(const int type, const RectBound& rectBound);
    void moveUp();
    void moveDown();
    ~Paddle();
private:
    Paddle() = delete;
    const Point_t dr{ 2,2 };
    const FPoint_t up_direct{ 0,-1.0 };
    const Point_t down_direct{ 0,1.0 };


};

