#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "note.h"

/*
 * represents a circle on the screen that does not move
 * user is attempting to hit notes that line up with this hit marker
 */
class Hit_Marker : public sf::Drawable
{
public:

	Hit_Marker(const sf::Vector2f& pos, float radius);

	/*
	 * determines if the given rect is colliding with the hit marker
	 */
	bool process_hit(const sf::FloatRect& rect);

	sf::CircleShape model;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};