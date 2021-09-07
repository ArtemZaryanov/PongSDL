#include "Entity.h"

Entity::Entity(const int type, const RectBound& rectBound):type(type)
{
	this->rectBound = rectBound;
	this->pos_LU.x = rectBound.x;
	this->pos_LU.y = rectBound.y;
	this->pos.x = (rectBound.x + rectBound.w) / 2;
	this->pos.y = (rectBound.y + rectBound.h) / 2;
	this->direct.x =0;
	this->direct.y = 0;

}

void Entity::move(const Point_t& dr, const Point_t& dir)
{
	this->direct = dir;
	this->rectBound.x += dr.x * this->direct.x;
	this->rectBound.y += dr.y * this->direct.y;
}

const RectBound& Entity::getRectBound() const
{
	return rectBound;
}

int Entity::getType() const
{
	return this->type;
}

Entity::~Entity()
{
}
