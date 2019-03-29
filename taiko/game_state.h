#pragma once

#include <SFML/Graphics.hpp>

class Game_State
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void get_input() = 0;
};