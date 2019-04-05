#include "game_state_play.h"

Game_State_Play::Game_State_Play(sf::RenderWindow* window) 
	: paused(false), n_gen(400.f, 1.0f, 40, sf::Vector2f(window->getSize().x + 200.f, window->getSize().y * 0.5f))
{ 
  this->window = window;
  
  	//initialize music object and load main theme
	if (!music.openFromFile("maintheme.ogg"))
	{
		//may be ideal to simply let program run without main theme
		std::cerr << "FATAL EXCEPTION: Failed to load main theme\n";
		exit(EXIT_FAILURE);
	}

	music.setLoop(true);
	music.play();
 
	this->render_backboard();
}

void Game_State_Play::draw()
{
	this->window->draw(this->backboard);
	
	this->window->draw(this->n_gen);

	return;
}

void Game_State_Play::update(const sf::Time dt)
{
	if (this->paused)
	{
		music.pause();
	}
	else
	{
		//without the conditional, music will constantly return to start
		if (music.getStatus() == sf::SoundSource::Paused) music.play();
	}

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
		std::cout << "OUTER\n";

	if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::D)
		std::cout << "INNER\n";

	if (event.key.code == sf::Keyboard::Space)
		paused = !paused;
}

void Game_State_Play::render_backboard()
{
	sf::Vector2u window_size = this->window->getSize();

	unsigned int backboard_width = window_size.x;
	unsigned int backboard_height = 100;

	this->backboard.setSize(sf::Vector2f(backboard_width, backboard_height));
	this->backboard.setOrigin(sf::Vector2f(0, backboard_height / 2));
	this->backboard.setFillColor(sf::Color::Blue);
	this->backboard.setPosition(0, window_size.y /2);
}