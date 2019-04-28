#include "game_state_menu.h"

/*
 * Initialize components for menu state
 */
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

/*
 * See Game_State::draw()
 */
void Game_State_Menu::draw() {
	//all drawing handled by TGUI
	gui.draw();
}

/*
 * See Game_State::update()
 */
void Game_State_Menu::update(const sf::Time dt) {
	return;
}

/*
 * See Game_State::get_input()
 */
void Game_State_Menu::get_input() {
	return;
}

/*
 * See Game_State::handle_event()
 */
void Game_State_Menu::handle_event(sf::Event event) {
	gui.handleEvent(event);
}

//define gui signal functions
void Game_State_Menu::playButtonPressed(){
	this->jukebox.pause(); //would be ideal to be able to start playing menu music again
	stateSwapRequested = true;
	toSwapTo = "STATE_PLAY";
}