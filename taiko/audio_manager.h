#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <iostream>
#include <memory>

/*
 * holds sound files in memory
 * currently unused
 */
class Audio_Manager
{
public:

	void create_sound(const std::string& name, const std::string& file_name);

	sf::Music& get_sound(const std::string& name);

private:

	std::map<std::string, std::unique_ptr<sf::Music> > sounds;
};