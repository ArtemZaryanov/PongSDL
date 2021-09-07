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
};

