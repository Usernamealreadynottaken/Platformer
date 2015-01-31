#include "level.h"

Level::Level() : camera_offset_x(0), camera_offset_y(0) { }

void Level::drawCameraOffsets(sf::RenderTarget & target)
{
	sf::Font font;
	font.loadFromFile("assets/arial.ttf");
	sf::Text offsets_text;
	offsets_text.setString("offset_x: " + std::to_string(camera_offset_x) +
		"\noffset_y: " + std::to_string(camera_offset_y));
	offsets_text.setFont(font);
	target.draw(offsets_text);
}