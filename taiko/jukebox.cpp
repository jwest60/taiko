#include "jukebox.h"

void Jukebox::play()
{
	this->music.play();
}

void Jukebox::pause()
{
	this->music.pause();
}

void Jukebox::openFromFile(const std::string& file_name)
{
	if (!this->music.openFromFile(file_name))
		std::cerr << "Jukebox failed to open file " << file_name << '\n';

	this->music.setLoop(true);
}

void Jukebox::setLoop(bool b)
{
	this->music.setLoop(b);
}