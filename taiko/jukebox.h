#pragma once

#include <SFML/Audio.hpp>
#include <iostream>

/*
 *	wrapper class for sf::Music
 *	allows for the extension of sf::Music
 */
class Jukebox
{
public:

	void play();
	void pause();

	void openFromFile(const std::string& file_name);

	void setLoop(bool b);

	sf::SoundSource::Status getStatus();

private:

	sf::Music music;
};