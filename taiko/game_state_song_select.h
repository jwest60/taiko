#pragma once

#include <SFML/Graphics.hpp>

#include <fstream>
#include <filesystem>

#include "game_state.h"
#include "texture_manager.h"
#include "jukebox.h"
#include "audio_manager.h"
#include "beatmap.h"

class Game_State_Song_Select : public Game_State
{
public:

	Game_State_Song_Select(sf::RenderWindow* window);

	virtual void draw();
	virtual void update(const sf::Time);
	virtual void get_input();
	virtual void handle_event(sf::Event);

private:

	void load_beatmaps();
	void create_beatmap(const std::string& path);

	bool paused;
	Jukebox jukebox;

	Texture_Manager tex_mgr;
	Audio_Manager audio_mgr;

	sf::Sprite bgsprite;

	Beatmap* selected;
	unsigned int s_index;

	std::vector<Beatmap> beatmaps;

	sf::Font font;
};