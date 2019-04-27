#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <stack>

#include "game_state.h"
#include "game_state_play.h"
#include "game_state_menu.h"

/*
 *	Holds states in memory for easy access
 */
class State_Manager
{
public:

	State_Manager();

	// create states and hold them in memory
	void create_states(sf::RenderWindow& window);
	// sets the current state
	bool set_state(const std::string& state);

	Game_State* get_current_state() const;

private:

	Game_State* current_state;

	// holds states, keys by the name of the state
	std::map<std::string, std::unique_ptr<Game_State> > states;
};