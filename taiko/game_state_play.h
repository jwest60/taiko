#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "game_state.h"

class Game_State_Play : public Game_State
{
public:

	Game_State_Play(sf::RenderWindow* window);

	virtual void draw();
	virtual void update();
	virtual void get_input();
	virtual void handle_event(sf::Event);

private:

	sf::RectangleShape backboard;
	void render_backboard();
};