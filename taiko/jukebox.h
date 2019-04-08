#pragma once

#include <SFML/Audio.hpp>
#include <iostream>

class Jukebox
{
public:

	void play();
	void pause();

	void openFromFile(const std::string& file_name);

	void setLoop(bool b);

private:

	sf::Music music;
};