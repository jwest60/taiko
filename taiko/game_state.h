#pragma once

#include <SFML/Graphics.hpp>

class Game_State
{
public:

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void get_input() = 0;
	virtual void handle_event(sf::Event) = 0;

	sf::RenderWindow* window;
};