#include "Ball.h"

Ball::Ball(const int type, const RectBound& rectBound):Entity(type,rectBound)
{
	direct.x = cosf(1000.0);
	direct.x = sinf(1000.0);

}

void Ball::move()
{
	rectBound.x = rectBound.x + dr.x * direct.x;
	rectBound.y = rectBound.y + dr.y * direct.y;
}
