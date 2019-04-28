#include "game_state_play.h"

/*
 * Initialize components for play state
 */
Game_State_Play::Game_State_Play(sf::RenderWindow* window)
	:
	paused(false),
	hits(0), misses(0),
	n_gen(400.f, 0.3f, 40, sf::Vector2f(window->getSize().x + 200.f, window->getSize().y * 0.5f)),
	backboard(window->getSize().x, 100, sf::Vector2f(0, window->getSize().y * 0.5f)),
	h_marker(sf::Vector2f(100.f, (float)(window->getSize().y / 2)), 40.f)
{ 
	this->window = window;

	this->load_textures();
	this->load_audio();

	if (!this->font.loadFromFile("pirulen.ttf")) { std::cerr << "Failed to load font" << std::endl; }

	this->score.setFont(this->font);
	this->score.setString("Hits: 0\nMisclicks: 0\nMissed notes: 0");
	this->score.setCharacterSize(30);
	this->score.setPosition(sf::Vector2f(50, 50));

	// To temporarily solve an issue with this song playing when the game launches
	// the game begins as paused and has to be manually unpaused at the beginning.
	// Ideally the file would be opened for the first time on pressing "play" so that
	// it's possible for the player to select a file to use from the menu.
	this->jukebox.openFromFile("taikosong1.ogg");
	this->jukebox.setLoop(false);
}

/*
 * See Game_State::draw()
 */
void Game_State_Play::draw()
{
	this->window->draw(this->bgsprite);
	this->window->draw(this->backboard);
	this->window->draw(this->n_gen);
	this->window->draw(this->h_marker);
	this->window->draw(this->score);

	return;
}

/*
 * See Game_State::update()
 */
void Game_State_Play::update(const sf::Time dt)
{
	if (!paused) this->n_gen.update(dt);

	// delay music so as to sync up to the notes reaching the hit marker
	if (this->jukebox.getStatus() == sf::SoundSource::Status::Stopped)
	{
		// nested if reduces the number of computations performed when jukebox is no longer stopped
		if (this->n_gen.start_music(this->h_marker.model.getPosition())) this->jukebox.play();
	}

	return;
}

/*
 * See Game_State::get_input()
 */
void Game_State_Play::get_input()
{
	return;
}

/*
 * See Game_State::handle_event()
 */
void Game_State_Play::handle_event(sf::Event event)
{
	if (event.type != sf::Event::KeyPressed) return;

	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::F)
	{
		auto n_col = this->n_gen.find_colliding_note(this->h_marker.model.getPosition().x);

		if (n_col == this->n_gen.notes.end()) return;

		if (n_col->get()->type == Note_Type::OUTER && this->h_marker.process_hit(n_col->get()->model.getGlobalBounds())) {
			hits++;
			this->n_gen.remove_note(n_col);
		}
		else misses++;

		this->update_score();
	}
		

	if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::D)
	{
		auto n_col = this->n_gen.find_colliding_note(this->h_marker.model.getPosition().x);

		if (n_col == this->n_gen.notes.end()) return;

		if (n_col->get()->type == Note_Type::INNER && this->h_marker.process_hit(n_col->get()->model.getGlobalBounds())) {
			hits++;
			this->n_gen.remove_note(n_col);
		}
		else misses++;

		this->update_score();
	}
		

	if (event.key.code == sf::Keyboard::Space)
	{
		paused = !paused;
		this->jukebox.pause();
		if (!this->paused && this->jukebox.getStatus() != sf::SoundSource::Status::Stopped) {
			this->jukebox.play();
		}
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		this->stateSwapRequested = true;
		this->toSwapTo = "STATE_MENU";
	}
}

/*
 * Load textures into memory and hand them off to the texture manager
 * See Texture_Manager
 */
void Game_State_Play::load_textures()
{
	this->tex_mgr.create_texture("background", "taikobg1.png");
	this->tex_mgr.create_texture("backboard", "backboard1.png");

	bgsprite.setTexture(this->tex_mgr.get_texture("background"));
	this->backboard.model.setTexture( &(this->tex_mgr.get_texture("backboard")) );
}

/*
 * Load sound files into memory and hand them off to the audio manager
 * See Audio_Manager
 */
void Game_State_Play::load_audio()
{
	return;
}

/*
 * Update string for score text object
 */
void Game_State_Play::update_score()
{
	std::string temp;
	temp = "Hits: " + std::to_string(hits) + "\nMisclicks: " + std::to_string(misses) + "\nMissed notes: " + std::to_string(this->n_gen.missed);
	this->score.setString(temp);
}