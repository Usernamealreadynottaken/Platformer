// SFML libs
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

// Custom types
#include "types.h"

// For debugging purpose
#include <windows.h>
#include "assert.h"

// Title, displayed only in windowed mode
static const char * window_title = "Platformer";
// Desired fps
static const uint32 fps = 60;

int main()
{
	// Get Desktop resolution
	const HWND hDesktop = GetDesktopWindow();
	RECT desktop;
	GetWindowRect(hDesktop, &desktop);
	int horizontal = desktop.right;
	int vertical = desktop.bottom;
	// Video modes retrieved are always valid
	// Reading them from a file, might require validation
	// Third, optional argument is a bit mask containing window style
	// Full screen
	//sf::RenderWindow window(sf::VideoMode(horizontal, vertical), window_title, sf::Style::Fullscreen);
	// Nice, clean window for debugging
	horizontal = 640;
	vertical = 480;
	sf::RenderWindow window(sf::VideoMode(640, 480), window_title);

	window.setFramerateLimit(fps);

	// Random irrelevant stuff, just for lulz
	float radius = 50.0f;
	sf::CircleShape circle(radius);
	sf::Vector2f position, velocity;
	position.x = 270.0f;
	position.y = 190.0f;
	velocity.x = 13.0f;
	velocity.y = 7.0f;
	circle.move(position);
	circle.setFillColor(sf::Color::Red);
	bool drag = false;
	float prevx = 0.0f;
	float prevy = 0.0f;
	sf::SoundBuffer sound_buffer;
	if (!sound_buffer.loadFromFile("bounce.wav")) {
		return -1;
	}
	sf::Sound sound;
	sound.setBuffer(sound_buffer);
	float scalex = 1.0f;
	float scaley = 1.0f;

	// Event handle
	sf::Event event;
	// Game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {

			// Upper right close button
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Key presses
			if (event.type == sf::Event::KeyPressed) {
				// Turn off on escape
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}


			// remove
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					float x = static_cast<float>(event.mouseButton.x) * scalex;
					float y = static_cast<float>(event.mouseButton.y) * scaley;
					float clickx = x - position.x;
					float clicky = y - position.y;
					if (clickx > 0.0f && clickx < radius * 2.0f && clicky > 0.0f && clicky < radius * 2.0f) {
						position.x = x - radius;
						position.y = y - radius;
						velocity.x = 0.0f;
						velocity.y = 0.0f;
						drag = true;
					}
				}
			}
			if (event.type == sf::Event::MouseMoved && drag) {
				prevx = position.x;
				prevy = position.y;
				position.x = event.mouseMove.x * scalex - radius;
				position.y = event.mouseMove.y * scaley - radius;
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left && drag) {
					velocity.x = position.x - prevx;
					velocity.y = position.y - prevy;
					drag = false;
				}
			}
			if (event.type == sf::Event::Resized) {
				scalex = static_cast<float>(horizontal) / static_cast<float>(event.size.width);
				scaley = static_cast<float>(vertical) / static_cast<float>(event.size.height);
			}


		}
		
		window.clear(sf::Color::Black);
		window.draw(circle);


		// bouncy
		circle.setPosition(position);
		prevx = position.x;
		prevy = position.y;
		position.x += velocity.x;
		position.y += velocity.y;
		if (position.x < 0.0f) {
			position.x = -position.x;
			velocity.x = -velocity.x;
			sound.play();
		} else if (position.x > static_cast<float>(horizontal) - 2 * radius) {
			position.x = static_cast<float>(horizontal << 1) - 4 * radius - position.x;
			velocity.x = - velocity.x;
			sound.play();
		}
		if (position.y < 0.0f) {
			position.y = -position.y;
			velocity.y = -velocity.y;
			sound.play();
		} else if (position.y > static_cast<float>(vertical) - 2 * radius) {
			position.y = static_cast<float>(vertical << 1) - 4 * radius - position.y;
			velocity.y = -velocity.y;
			sound.play();
		}


		window.display();
	}
	
	return 0;
}