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
#include "game_state_song_select.h"

class State_Manager
{
public:

	State_Manager();
	~State_Manager();

	void add_state(const std::string& name, Game_State* state);
	bool set_state(const std::string& state);
	Game_State* get_current_state() const;

private:

	Game_State* current_state;

	std::map<std::string, Game_State*> states;
};