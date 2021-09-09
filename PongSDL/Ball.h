#pragma once
#include "Entity.h"
class Ball :
    public Entity
{
public:
    Ball(const int type, const RectBound& rectBound);
    void move();
private:
    const Point_t dr{ 2,2 };
    Ball() = delete;
};

