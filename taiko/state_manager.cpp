#include "state_manager.h"

State_Manager::State_Manager() : current_state(nullptr) {}

void State_Manager::create_states(sf::RenderWindow& window)
{
	this->states.insert(std::make_pair("STATE_PLAY", std::make_unique<Game_State_Play>(&window)));
	this->states.insert(std::make_pair("STATE_MENU", std::make_unique<Game_State_Menu>(&window)));
}

bool State_Manager::set_state(const std::string& state)
{
	try 
	{
		this->current_state = this->states[state].get();
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "WARNING: Attempting to set non-existent state " << state << '\n';
		return false;
	}

	return true;
}

Game_State* State_Manager::get_current_state() const
{
	return this->current_state;
}