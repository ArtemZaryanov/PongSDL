#pragma once
#include "Entity.h"
class Paddle :
    public Entity
{
public:
    Paddle();
    void moveUp();
    void moveDown();
    ~Paddle();
};

