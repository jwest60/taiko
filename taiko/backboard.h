#pragma once

#include <SFML/Graphics.hpp>

/*
 * this is the board that the notes slide down on
 */
struct Backboard : public sf::Drawable
{
	Backboard(unsigned int backboard_width, unsigned int backboard_height, const sf::Vector2f& pos);

	sf::RectangleShape model;

	unsigned int width;
	unsigned int height;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};