#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "game_state.h"

struct Game_State_Play : public Game_State
{
	virtual void draw();
	virtual void update();
	virtual void get_input();
	virtual void handle_event(sf::Event);
};