#include "Paddle.h"

Paddle::Paddle(const int type, const RectBound& rectBound) :Entity(type,rectBound)
{
	//this->rectBound = rectBound;
	//this->pos_LU->x = rectBound->x;
	//this->pos_LU->y = rectBound->y;
	//this->pos->x = (rectBound->x + rectBound->w) / 2;
	//this->pos->y = (rectBound->y + rectBound->h) / 2;
	//this->direct->x = 0;
	//this->direct->y = 0;
}

void Paddle::moveUp()
{
}

void Paddle::moveDown()
{
}

Paddle::~Paddle()
{
}
