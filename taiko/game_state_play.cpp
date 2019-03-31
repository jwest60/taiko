#include "game_state_play.h"

Game_State_Play::Game_State_Play() : paused(false)
{
	//initialize music object and load main theme
	if (!music.openFromFile("maintheme.ogg"))
	{
		//may be ideal to simply let program run without main theme
		std::cerr << "FATAL EXCEPTION: Failed to load main theme\n";
		exit(EXIT_FAILURE);
	}

	music.setLoop(true);
	music.play();
}

void Game_State_Play::draw()
{
	return;
}

void Game_State_Play::update()
{
	if (this->paused)
	{
		music.pause();
	}
	else
	{
		//without the conditional, music will constantly return to start
		if (music.getStatus() == sf::SoundSource::Paused) music.play();
	}

	return;
}

void Game_State_Play::get_input()
{
	return;
}

void Game_State_Play::handle_event(sf::Event event)
{
	if (event.type != sf::Event::KeyPressed) return;

	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::F)
		std::cout << "OUTER\n";

	if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::D)
		std::cout << "INNER\n";

	if (event.key.code == sf::Keyboard::Space)
		paused = !paused;
}