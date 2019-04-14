#include "hit_marker.h"

Hit_Marker::Hit_Marker(const sf::Vector2f& pos, unsigned int radius)
{
	this->model.setRadius(radius);
	this->model.setOrigin(radius, radius);
	this->model.setPosition(pos);
	this->model.setFillColor(sf::Color(0, 255, 0, 140));
}

bool Hit_Marker::process_hit(const sf::FloatRect& rect)
{
	if (rect.contains(this->model.getPosition())) 
		return true;

	return false;
}

void Hit_Marker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->model);
}