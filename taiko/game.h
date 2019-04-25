#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>

#include "state_manager.h"
#include "game_state.h"

class Game
{
public:

	sf::RenderWindow window;

	Game();

	void game_loop();

	State_Manager state_mgr;
};