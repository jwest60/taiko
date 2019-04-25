#include "game.h"

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Taiko");

	this->state_mgr.add_state("STATE_MENU", new Game_State_Menu(&this->window));
	this->state_mgr.add_state("STATE_SELECT", new Game_State_Song_Select(&this->window));
	this->state_mgr.add_state("STATE_PLAY", new Game_State_Play(&this->window));
	this->state_mgr.set_state("STATE_MENU");
}

void Game::game_loop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		auto current_state = this->state_mgr.get_current_state();
		if (current_state == nullptr)
		{
			std::cerr << "FATAL EXCEPTION: Attempting to handle non-existent current state\n";
			exit(EXIT_FAILURE);
		}

		sf::Time dt = clock.restart();

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}

			current_state->handle_event(event);
		}

		current_state->get_input();
		current_state->update(dt);
		window.clear(sf::Color::Black);
		current_state->draw();

		if (current_state->stateSwapRequested) {
			current_state->stateSwapRequested = false;
			this->state_mgr.set_state(current_state->toSwapTo);
		}

		window.display();
	}
}

