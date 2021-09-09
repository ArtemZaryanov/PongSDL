#include "Entity.h"

Entity::Entity(const int type, const RectBound& rectBound):type(type)
{
	this->rectBound = rectBound;
	this->direct.x =0.0;
	this->direct.y =0.0;
	Update();

}
void Entity::move(Point_t&& dr, FPoint_t&& dir)
{
	direct = dir;
	rectBound.x += dr.x * this->direct.x;
	rectBound.y += dr.y * this->direct.y;
	Update();
}
void Entity::move(const Point_t& dr, const FPoint_t& dir)
{
	direct = dir;
	rectBound.x += dr.x * this->direct.x;
	rectBound.y += dr.y * this->direct.y;
	Update();
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

void Entity::Update()
{
	pos_LU.x = rectBound.x;
	pos_LU.y = rectBound.y;
	pos.x = (rectBound.x + rectBound.w) / 2;
	pos.y = (rectBound.y + rectBound.h) / 2;
}
