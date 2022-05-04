#include "Collision.h"

bool Collision::checkCollision(const Entity& e1, const Entity& e2)
{
	//самому
	 
	return e1.getType() == e2.getType();
}
