#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <queue>
#include <memory>
#include <iostream>
#include <random>
#include <fstream>
#include <sstream>

#include "note.h"
#include "texture_manager.h"

class Note_Generator : public sf::Drawable
{
public:

	Note_Generator(float velocity, float rate, unsigned int n_radius, sf::Vector2f spawn);

	void update(const sf::Time dt);

	std::deque<std::unique_ptr<Note> >::iterator find_colliding_note(const float x);

	// Note& get_note_at_index(int i);

	void remove_note(std::deque<std::unique_ptr<Note> >::iterator note);

	Note_Type get_note_type(int type);

	unsigned int missed;

	// returns true once the appropriate amount of time has passed to (hopefully) sync up the music
	bool start_music(const sf::Vector2f& hitpos);

private:

	std::mt19937 mt;
	std::uniform_int_distribution<int> uid;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Time t;

	// the speed at which the notes will move
	float velocity;
	// the rate in seconds at which notes will be generated
	float rate;

	// holds times at which notes occur
	std::queue<unsigned long> note_times;

	// the radius of the notes
	unsigned int n_radius;

	// the position that notes will spawn
	sf::Vector2f spawn;

	std::deque<std::unique_ptr<Note> > notes;

	void generate_notes(const sf::Time dt);

	Texture_Manager tex_mgr;
};