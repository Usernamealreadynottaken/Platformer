#pragma once

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class Entity
{
public:
	Entity();
	~Entity();
	void move(int x, int y);
	sf::Sprite getSprite() { return sprite; }
	void setSprite(sf::Sprite s) { sprite = s; }
protected:
private:
	sf::Sprite sprite;
};