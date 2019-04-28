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

/*
 * Generates and manages notes with quantity and timing given by beatmap.osu file
 */
class Note_Generator : public sf::Drawable
{
public:

	// initialize random number generator and note generation
	Note_Generator(float velocity, float rate, unsigned int n_radius, sf::Vector2f spawn);

	/*
	 * updates the positions of the notes on the screen 
	 * distance is dependent on dt
	 */
	void update(const sf::Time dt);

	/*
	 * determines if a note is colliding at the given x position
	 */
	std::deque<std::unique_ptr<Note> >::iterator find_colliding_note(const float x);

	// deletes the given note from the deque
	void remove_note(std::deque<std::unique_ptr<Note> >::iterator note);

	// converts int to enum
	Note_Type get_note_type(int type);

	// the number of notes that were missed
	unsigned int missed;

	// returns true once the appropriate amount of time has passed to (hopefully) sync up the music
	bool start_music(const sf::Vector2f& hitpos);

	// holds all the notes currently on the screen
	std::deque<std::unique_ptr<Note> > notes;

private:

	// random number generation using the std random library
	std::mt19937 mt;
	std::uniform_int_distribution<int> uid;

	// draws notes to the screen
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// used by generate notes to determine if its time for the next note to be generated
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

	// generates notes, the rate given by dt
	void generate_notes(const sf::Time dt);

	// this shouldnt be here lol
	Texture_Manager tex_mgr;
};