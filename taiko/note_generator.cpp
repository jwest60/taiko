#include "note_generator.h"

// initialize random number generator and customize notes to be generated
Note_Generator::Note_Generator(
	float velocity,
	float rate,
	unsigned int n_radius,
	sf::Vector2f spawn)
	:
	velocity(velocity),
	rate(rate),
	n_radius(n_radius),
	spawn(spawn),
	uid(1, 2),
	missed(0)
{
	std::random_device rd{};
	this->mt.seed(rd());

	this->tex_mgr.create_texture("inner", "notein1.png");
	this->tex_mgr.create_texture("outer", "noteout1.png");

	// process osu beatmap
	std::istringstream iss;
	std::ifstream ifs;
	std::string line, note_time;

	ifs.open("beatmap.osu");

	// skip through file to HitObjects
	while (std::getline(ifs, line)){ if (line == "[HitObjects]") break; }

	// process objects and add to note_times
	while (std::getline(ifs, line))
	{
		iss.str(line);
		//run command 3 times to skip over x and y
		std::getline(iss, note_time, ',');
		std::getline(iss, note_time, ',');
		std::getline(iss, note_time, ',');

		this->note_times.push( std::stoul(note_time) );
	}
}

// draws all notes currently in the deque
void Note_Generator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto it = this->notes.begin(); it != this->notes.end(); ++it)
	{
		target.draw(*it->get());
	}
}

/*
 *	updates note positions, distance depends on dt
 *	See Game::game_loop() for a description of dt
 */ 
void Note_Generator::update(const sf::Time dt)
{
	this->generate_notes(dt);

	if (this->notes.empty()) return;

	if (this->notes.front()->model.getPosition().x + this->notes.front()->model.getRadius() < 0)
	{
		this->notes.pop_front();
		this->missed++;
	}
	
	for (size_t i = 0; i < this->notes.size(); ++i)
		this->notes[i]->move(dt);
}

void Note_Generator::generate_notes(const sf::Time dt)
{
	// determines if enough time has passed to generate the next note
	sf::Time elapsed = this->t + dt;

	if (note_times.empty()) return;

	unsigned long next_note_time = this->note_times.front();

	if (elapsed.asMilliseconds() >= next_note_time)
	{
		//this->t = sf::Time::Zero;

		int note_type = this->uid(this->mt);
		Note_Type type = this->get_note_type(note_type);

		this->notes.emplace_back(new Note(this->velocity, this->n_radius, this->spawn, type, tex_mgr));

		this->note_times.pop();
	}

	this->t += dt;
}

/*
 * determines if a note exists at the given x position
 * returns an iterator to that note if true
 * otherwise returns the end of the note deque
 */
std::deque<std::unique_ptr<Note> >::iterator Note_Generator::find_colliding_note(const float x)
{
	for (auto it = this->notes.begin(); it != this->notes.end(); ++it)
	{
		if (it->get()->model.getPosition().x + it->get()->model.getRadius() < x) continue;
		return it;
	}

	return this->notes.end();
}

void Note_Generator::remove_note(std::deque<std::unique_ptr<Note> >::iterator note)
{
	this->notes.erase(note);
}

/*
 * simple translator from int to enum
 */
Note_Type Note_Generator::get_note_type(int type)
{
	switch (type)
	{
	case 1:
		return Note_Type::INNER;
	case 2:
		return Note_Type::OUTER;
	default:
		return Note_Type::INNER;
	}
}

/*
 * Called by game_state_play; returns true when the notes have caught up to the music
 */
bool Note_Generator::start_music(const sf::Vector2f& hitpos)
{
	//goal is to delay music by the amount of time it takes a note to move from spawn to hit marker
	//v = d/t; t = d/v
	//velocity is given, d = spawn.x - hitpos.x
	if (this->note_times.empty()) return false;
	if (this->t.asSeconds() >= (spawn.x - hitpos.x) / this->velocity) return true;
	return false;
}