#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(const char* fileText)
{
	if (fileText[0] == '1')
	{

	}
}

const RectBound& Entity::getRectBound() const
{
	return rectBound;
}

const Texture& Entity::getTexture() const
{
	return texture;
}

Entity::~Entity()
{
}
