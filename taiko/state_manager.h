#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <stack>

#include "game_state.h"
#include "game_state_play.h"

class State_Manager
{
public:

	State_Manager();

	bool set_state(const std::string& state);

	Game_State* get_current_state() const;

private:

	void create_states();

	Game_State* current_state;

	std::map<std::string, std::unique_ptr<Game_State> > states;
};