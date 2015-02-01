#pragma once

#include <SFML\Graphics.hpp>

class Level
{
public:
	Level();
	~Level();
	void drawCameraOffsets(sf::RenderTarget & target);
protected:
private:
	int camera_offset_x;
	int camera_offset_y;
};