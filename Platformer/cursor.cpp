#include "cursor.h"

Cursor::Cursor() : _position(0.0f, 0.0f)
{
	texture.loadFromFile("../assets/cursor.png");
	sprite.setTexture(texture);
}

Cursor::~Cursor() { }

void Cursor::updatePosition(int x, int y)
{
	_position.x = static_cast<float>(x);
	_position.y = static_cast<float>(y);
	sprite.setPosition(_position);
}