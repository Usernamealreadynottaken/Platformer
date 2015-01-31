// SFML libs
#include <SFML\Graphics.hpp>

// Custom types
#include "types.h"

// For debugging purpose
#include "assert.h"

// Editor classes
#include <Windows.h>
#include "level.h"

// Title, displayed only in windowed mode
static const char * window_title = "Level Editor";
// Desired fps
static const uint32 fps = 60;
// Base screen resolution
static const int horizontal_resolution = 1920;
static const int vertical_resolution = 1080;

int main()
{
	// Get Desktop resolution
	const HWND hDesktop = GetDesktopWindow();
	RECT desktop;
	GetWindowRect(hDesktop, &desktop);
	int horizontal = desktop.right * 2 / 3;
	int vertical = desktop.bottom * 2 / 3;
	// Window scale
	float scalex = static_cast<float>(horizontal_resolution) / static_cast<float>(horizontal);
	float scaley = static_cast<float>(vertical_resolution) / static_cast<float>(vertical);
	sf::RenderWindow window(sf::VideoMode(horizontal, vertical), window_title);
	window.setFramerateLimit(fps);

	// Level
	Level level;

	// Event handle
	sf::Event event;
	// Game loop
	while (window.isOpen()) {

		while (window.pollEvent(event)) {

			// Upper right close button
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		level.drawCameraOffsets(window);
		window.display();
	}

	return 0;
}