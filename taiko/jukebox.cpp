#include "jukebox.h"

void Jukebox::play()
{
	this->music.play();
}

void Jukebox::pause()
{
	this->music.pause();
}

// attempt to play a song from a file
void Jukebox::openFromFile(const std::string& file_name)
{
	if (!this->music.openFromFile(file_name))
		std::cerr << "Jukebox failed to open file " << file_name << '\n';

	this->music.setLoop(true);
	this->music.stop();
}

// set the music to loop or not
void Jukebox::setLoop(bool b)
{
	this->music.setLoop(b);
}

// get the status of the sound (playing, paused, etc.)
sf::SoundSource::Status Jukebox::getStatus()
{
	return this->music.getStatus();
}