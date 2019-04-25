#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "note.h"

class Hit_Marker : public sf::Drawable
{
public:

	Hit_Marker(const sf::Vector2f& pos, float radius);

	bool process_hit(const sf::FloatRect& rect);

	sf::CircleShape model;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};