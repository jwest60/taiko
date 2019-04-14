#include "note.h"

sf::Color get_color(Note_Type type)
{
	switch (type)
	{
	case Note_Type::INNER:
		return sf::Color::Green;
	case Note_Type::OUTER:
		return sf::Color::Magenta;
	default:
		return sf::Color::Black;
	}
}

Note::Note(float velocity, unsigned int radius, sf::Vector2f& pos, Note_Type type) 
	: velocity(velocity), type(type)
{
	this->model.setFillColor(get_color(type));
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