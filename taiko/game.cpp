#include "game.h"

/*
 *	Create states for menu and window
 */
Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Taiko");

	this->state_mgr.create_states(this->window);
	this->state_mgr.set_state("STATE_MENU");
}

/*
 *	Main cycle of the game; draws, updates, and handles input
 */
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

		/*
		 *	dt = delta time
		 *	the time since the last iteration (i.e. the last frame)
		 *	ensures the game runs at the same speed regardless of fps
		 */
		sf::Time dt = clock.restart();

		/*
		 *	Event listener
		 */
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}

			/*
			 *	Gives the state the chance to handle events
			 */
			current_state->handle_event(event);
		}

		// get user input
		current_state->get_input();
		// update state components
		current_state->update(dt);
		// clear the screen (this must be done before a draw, sfml's rules not mine)
		window.clear(sf::Color::Black);
		// draw components of the state to the screen
		current_state->draw();

		/*
		 * gives the opportunity for a state to handle a change in state
		 */
		if (current_state->stateSwapRequested) {
			current_state->stateSwapRequested = false;
			this->state_mgr.set_state(current_state->toSwapTo);
		}

		window.display();
	}
}

