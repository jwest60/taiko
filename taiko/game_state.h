#pragma once

#include <SFML/Graphics.hpp>

#include "game.h"

class Game_State
{
public:

	virtual void draw() = 0;
	virtual void update(const sf::Time) = 0;
	virtual void get_input() = 0;
	virtual void handle_event(sf::Event) = 0;

	sf::RenderWindow* window;

	//slightly awkward implementation of state swap functionality in game.cpp
	bool stateSwapRequested = false;
	std::string toSwapTo;
};