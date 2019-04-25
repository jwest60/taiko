#include "state_manager.h"

State_Manager::State_Manager() : current_state(nullptr) {}

void State_Manager::add_state(const std::string& name, Game_State* state)
{
	this->states.insert(std::make_pair(name, state));
}

bool State_Manager::set_state(const std::string& state)
{
	try 
	{
		this->current_state = this->states[state];
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

State_Manager::~State_Manager()
{
	for (auto it = this->states.begin(); it != this->states.end(); ++it)
		delete it->second;
}