#include "audio_manager.h"

void Audio_Manager::create_sound(const std::string& name, const std::string& file_name)
{
	auto m = this->sounds.emplace(name, new sf::Music);

	if (!m.first->second->openFromFile(file_name)) 
	{
		std::cerr << "warning: could not find file " << file_name << '\n';
		this->sounds.erase(m.first);

		return;
	}
}

sf::Music& Audio_Manager::get_sound(const std::string& name)
{
	try
	{
		return *this->sounds.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "FATAL EXCEPTION: failed to get music because sound does not exist: " << name << std::endl;
		exit(EXIT_FAILURE);
	}
}