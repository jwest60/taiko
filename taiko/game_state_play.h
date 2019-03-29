#pragma once

#include "game_state.h"

struct Game_State_Play : public Game_State
{
	virtual void draw();
	virtual void update();
	virtual void get_input();
};