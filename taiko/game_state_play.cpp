#include "game_state_play.h"

void Game_State_Play::draw()
{
	return;
}

void Game_State_Play::update()
{
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