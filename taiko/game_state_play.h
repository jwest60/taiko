#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>

#include "game_state.h"
#include "note_generator.h"
#include "backboard.h"
#include "texture_manager.h"
#include "audio_manager.h"
#include "jukebox.h"
#include "hit_marker.h"

/*
 *	class that holds components that will be used during the play state
 *	i.e. the state where the user must hit notes to a beat
 */
class Game_State_Play : public Game_State
{
public:

	Game_State_Play(sf::RenderWindow* window);

	virtual void draw();
	virtual void update(const sf::Time);
	virtual void get_input();
	virtual void handle_event(sf::Event);

private:

	void load_textures();
	void load_audio();

	void update_score();

	bool paused;

	sf::Sprite bgsprite;

	sf::Font font;
	sf::Text score;

	unsigned int hits, misses;

	// custom implementations, see individual classes for documentation
	Jukebox jukebox;

	Texture_Manager tex_mgr;
	Audio_Manager audio_mgr;

	Hit_Marker h_marker;

	Backboard backboard;
	Note_Generator n_gen;
};