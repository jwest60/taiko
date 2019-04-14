#include "game_state_play.h"

Game_State_Play::Game_State_Play(sf::RenderWindow* window)
	:
	paused(false),
	n_gen(400.f, 0.3f, 40, sf::Vector2f(window->getSize().x + 200.f, window->getSize().y * 0.5f)),
	backboard(window->getSize().x, 100, sf::Vector2f(0, window->getSize().y * 0.5f)),
	h_marker(sf::Vector2f(100.f, window->getSize().y / 2), 40)
{ 
	this->window = window;

	this->load_textures();
	this->load_audio();

	this->jukebox.openFromFile("maintheme.ogg");
	this->jukebox.setLoop(true);
	this->jukebox.play();
}

void Game_State_Play::draw()
{
	this->window->draw(this->backboard);
	this->window->draw(this->n_gen);
	this->window->draw(this->h_marker);

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

		if (n_col->get()->type == Note_Type::OUTER && this->h_marker.process_hit(n_col->get()->model.getGlobalBounds()))
			this->n_gen.remove_note(n_col);
	}
		

	if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::D)
	{
		auto n_col = this->n_gen.find_colliding_note(this->h_marker.model.getPosition().x);

		if (n_col->get()->type == Note_Type::INNER && this->h_marker.process_hit(n_col->get()->model.getGlobalBounds()))
			this->n_gen.remove_note(n_col);
	}
		

	if (event.key.code == sf::Keyboard::Space)
	{
		paused = !paused;
		this->paused ? this->jukebox.pause() : this->jukebox.play();
	}
}

void Game_State_Play::load_textures()
{
	return;
}

void Game_State_Play::load_audio()
{
	return;
}