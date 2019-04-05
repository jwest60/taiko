#include "note_generator.h"

Note_Generator::Note_Generator(
	float velocity, 
	float rate, 
	unsigned int n_radius, 
	sf::Vector2f spawn) 
	: 
	velocity(velocity), 
	rate(rate),
	n_radius(n_radius),
	spawn(spawn) {}

void Note_Generator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = this->notes.begin(); it != this->notes.end(); ++it)
	{
		target.draw(*it->get());
	}
}

void Note_Generator::update(const sf::Time dt)
{
	this->generate_notes(dt);

	if (this->notes.empty()) return;

	if (this->notes.front()->model.getPosition().x + this->notes.front()->model.getRadius() < 0)
		this->notes.pop_front();
	
	for (size_t i = 0; i < this->notes.size(); ++i)
		this->notes[i]->move(dt);
}

void Note_Generator::generate_notes(const sf::Time dt)
{
	sf::Time elapsed = this->t + dt;

	if (elapsed.asSeconds() > this->rate)
	{
		this->t = sf::Time::Zero;
		this->notes.emplace_back(new Note(this->velocity, this->n_radius, this->spawn));

		return;
	}

	this->t += dt;
}