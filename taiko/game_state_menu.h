#pragma once

#include <TGUI/TGUI.hpp> //also uncludes SFML/Graphics.hpp
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>

#include "game_state.h"
#include "jukebox.h"

/*
 *	Menu state, first state of the game
 *	Provides options for the user to go to the play state
 */
class Game_State_Menu : public Game_State
{
public:

	Game_State_Menu(sf::RenderWindow* window);

	virtual void draw();
	virtual void update(const sf::Time);
	virtual void get_input();
	virtual void handle_event(sf::Event);
	
private:

	tgui::Gui gui;
	tgui::Button::Ptr playButton;
	tgui::Picture::Ptr bgImage;
	void playButtonPressed();

	Jukebox jukebox;
};