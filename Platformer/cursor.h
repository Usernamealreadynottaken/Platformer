#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

class Cursor
{
public:
	Cursor();
	~Cursor();
	sf::Sprite sprite;
	void updatePosition(int x, int y);
protected:
private:
	sf::Vector2f _position;
	sf::Texture texture;
};