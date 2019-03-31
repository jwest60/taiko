#include "game_state_play.h"

Game_State_Play::Game_State_Play(sf::RenderWindow* window) : paused(false)
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

	return;
}

void Game_State_Play::update()
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