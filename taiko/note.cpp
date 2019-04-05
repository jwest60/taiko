#include "note.h"

Note::Note(float velocity, unsigned int radius, sf::Vector2f& pos) : velocity(velocity)
{
	this->model.setFillColor(sf::Color::Green);
	this->model.setRadius(radius);
	this->model.setOrigin(radius, radius);
	this->model.setPosition(pos);
}

void Note::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->model);
}

void Note::move(sf::Time t)
{
	float dt = t.asSeconds();
	this->model.move(this->velocity * dt * -1, 0);
}