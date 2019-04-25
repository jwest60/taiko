#include "game_state_menu.h"

Game_State_Menu::Game_State_Menu(sf::RenderWindow* window)
{
	this->window = window;
	this->gui.setTarget((*window));

	//initialize menu elements
	this->bgImage = tgui::Picture::create("titlebg.png");
	this->bgImage->setPosition("0%", "0%");
	this->bgImage->setSize("100%", "100%");
	gui.add(bgImage);

	this->playButton = tgui::Button::create();
	this->playButton->setPosition("40%", "60%");
	this->playButton->setSize("20%", "10%");
	this->playButton->setText("Play");
	gui.add(playButton);

	this->playButton->connect("pressed", &Game_State_Menu::playButtonPressed, this);

	//initialize jukebox and play music
	this->jukebox.openFromFile("maintheme.ogg");
	this->jukebox.setLoop(true);
	this->jukebox.play();
}

void Game_State_Menu::draw() {
	//anything below gui (background images etc.) goes here
	gui.draw();
}

void Game_State_Menu::update(const sf::Time dt) {
	//uhh update your stuff
}

void Game_State_Menu::get_input() {
	return;
}

void Game_State_Menu::handle_event(sf::Event event) {
	gui.handleEvent(event);
}

//define gui signal functions
void Game_State_Menu::playButtonPressed(){
	this->jukebox.pause(); //would be ideal to be able to start playing menu music again
	stateSwapRequested = true;
	toSwapTo = "STATE_SELECT";
}