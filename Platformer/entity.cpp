#include "entity.h"

Entity::Entity() { }

Entity::~Entity() { }

void Entity::move(int x, int y)
{
	sprite.move(static_cast<float>(x), static_cast<float>(y));
}