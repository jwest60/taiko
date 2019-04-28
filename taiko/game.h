#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>

#include "state_manager.h"
#include "game_state.h"

/*
 *	Manages all components that must continue throughout the lifetime of the game.
 */
class Game
{
public:

	// SFML window
	sf::RenderWindow window;

	Game();

	// The internal loop that draws and updates the game
	void game_loop();

private:

	// Deprecated
	std::stack<Game_State *> states;

	// Manages states and determines what comes first
	State_Manager state_mgr;
};