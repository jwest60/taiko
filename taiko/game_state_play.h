#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>

#include "game_state.h"
#include "note_generator.h"
#include "backboard.h"

class Game_State_Play : public Game_State
{
public:

	Game_State_Play(sf::RenderWindow* window);

	virtual void draw();
	virtual void update(const sf::Time);
	virtual void get_input();
	virtual void handle_event(sf::Event);

private:

	bool paused;
	sf::Music music;

	Backboard backboard;
	Note_Generator n_gen;
};