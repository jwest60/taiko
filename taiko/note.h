#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

struct Note : public sf::Drawable
{
	Note(float velocity, unsigned int radius, sf::Vector2f& pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::CircleShape model;

	float velocity;

	void move(sf::Time t);
};