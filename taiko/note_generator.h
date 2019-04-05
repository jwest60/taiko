#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <memory>
#include <iostream>

#include "note.h"

class Note_Generator : public sf::Drawable
{
public:

	Note_Generator(float velocity, float rate, unsigned int n_radius, sf::Vector2f spawn);

	void update(const sf::Time dt);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Time t;

	// the speed at which the notes will move
	float velocity;
	// the rate in seconds at which notes will be generated
	float rate;

	// the radius of the notes
	unsigned int n_radius;

	// the position that notes will spawn
	sf::Vector2f spawn;

	std::deque<std::unique_ptr<Note> > notes;

	void generate_notes(const sf::Time dt);
};