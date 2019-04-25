#include "game_state_song_select.h"

namespace fs = std::experimental::filesystem;

Game_State_Song_Select::Game_State_Song_Select(sf::RenderWindow* window) : s_index(0)
{
	this->window = window;
	this->load_beatmaps();

	this->font.loadFromFile("f_game.ttf");
}

void Game_State_Song_Select::load_beatmaps()
{
	std::string path = "songs";

	for (const auto & bm : fs::directory_iterator(path))
	{
		std::string bm_path = bm.path().string();

		for (const auto & osu : fs::directory_iterator(bm_path))
		{
			std::string o_path = osu.path().string();

			if (o_path.substr(o_path.find_last_of(".") + 1) == "osu")
				this->beatmaps.emplace_back(o_path);
		}
	}

	this->selected = &this->beatmaps.front();
}

void Game_State_Song_Select::draw()
{
	sf::Text name;
	name.setFont(this->font);

	for (size_t i = 0; i < this->beatmaps.size(); ++i)
	{
		std::string display;

		if (this->selected == &this->beatmaps[i])
			display += "> ";

		display += this->beatmaps[i].title;
		name.setString(display);
		name.setPosition(this->window->getSize().x / 2, 100 * i);
		
		this->window->draw(name);
	}
}

void Game_State_Song_Select::update(const sf::Time dt)
{

}

void Game_State_Song_Select::get_input()
{

}

void Game_State_Song_Select::handle_event(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Down)
	{
		if (this->s_index < this->beatmaps.size() - 1)
		{
			this->s_index += 1;
			this->selected = &this->beatmaps[s_index];
		}
	}

	if (event.key.code == sf::Keyboard::Up)
	{
		if (this->s_index > 0)
		{
			this->s_index -= 1;
			this->selected = &this->beatmaps[s_index];
		}
	}

	if (event.key.code == sf::Keyboard::Enter)
	{
		
	}
}