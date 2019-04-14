#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum class Note_Type { INNER, OUTER };

struct Note : public sf::Drawable
{
	Note_Type type;

	Note(float velocity, unsigned int radius, sf::Vector2f& pos, Note_Type type);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::CircleShape model;

	float velocity;

	void move(sf::Time t);
};