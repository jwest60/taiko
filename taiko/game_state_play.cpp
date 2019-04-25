#include "game_state_play.h"

Game_State_Play::Game_State_Play(sf::RenderWindow* window)
	:
	paused(true),
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
	this->jukebox.setLoop(true);
}

void Game_State_Play::draw()
{
	this->window->draw(this->bgsprite);
	this->window->draw(this->backboard);
	this->window->draw(this->n_gen);
	this->window->draw(this->h_marker);
	this->window->draw(this->score);

	return;
}

void Game_State_Play::update(const sf::Time dt)
{
	if (!paused) this->n_gen.update(dt);

	return;
}

void Game_State_Play::get_input()
{
	return;
}

void Game_State_Play::handle_event(sf::Event event)
{
	if (event.type != sf::Event::KeyPressed) return;

	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::F)
	{
		auto n_col = this->n_gen.find_colliding_note(this->h_marker.model.getPosition().x);

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
		this->paused ? this->jukebox.pause() : this->jukebox.play();
	}
}

void Game_State_Play::load_textures()
{
	this->tex_mgr.create_texture("background", "taikobg1.png");
	this->tex_mgr.create_texture("backboard", "backboard1.png");

	bgsprite.setTexture(this->tex_mgr.get_texture("background"));
	this->backboard.model.setTexture( &(this->tex_mgr.get_texture("backboard")) );
}

void Game_State_Play::load_audio()
{
	return;
}

void Game_State_Play::update_score()
{
	std::string temp;
	temp = "Hits: " + std::to_string(hits) + "\nMisclicks: " + std::to_string(misses) + "\nMissed notes: " + std::to_string(this->n_gen.missed);
	this->score.setString(temp);
}