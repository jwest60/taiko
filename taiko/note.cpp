#include "note.h"

// translates enum to a color
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

sf::Texture get_texture(Texture_Manager t_m, Note_Type t) {
	switch (t)
	{
	case Note_Type::INNER:
		return (t_m.get_texture("inner"));
	case Note_Type::OUTER:
		return (t_m.get_texture("outer"));
	default:
		exit(EXIT_FAILURE);
	}
}

Note::Note(float velocity, unsigned int radius, sf::Vector2f& pos, Note_Type type, Texture_Manager& tex_mgr) 
	: velocity(velocity), type(type)
{
	//store texture in member variable then assign to model
	this->tex = get_texture(tex_mgr, type);
	this->model.setTexture(&this->tex);
	//set remaining attributes
	this->model.setRadius(radius);
	this->model.setOrigin(radius, radius);
	this->model.setPosition(pos);
}

void Note::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->model);
}

// move the note across the screen
void Note::move(sf::Time t)
{
	float dt = t.asSeconds();
	this->model.move(this->velocity * dt * -1, 0);
}