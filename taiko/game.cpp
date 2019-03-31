#include "game.h"

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Taiko");

	this->state_mgr.create_states(this->window);
	this->state_mgr.set_state("STATE_PLAY");
}

void Game::game_loop()
{
	while (window.isOpen())
	{
		sf::Event event;
		auto current_state = this->state_mgr.get_current_state();
		if (current_state == nullptr)
		{
			std::cerr << "FATAL EXCEPTION: Attempting to handle non-existent current state\n";
			exit(EXIT_FAILURE);
		}

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
		current_state->update();
		window.clear(sf::Color::Red);
		current_state->draw();

		window.display();
	}
}

