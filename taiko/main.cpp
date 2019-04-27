#include <SFML/Graphics.hpp>

#include "game.h"
#include "game_state_play.h"

int main()
{
	// create an instance of game and begin the game loop
	Game game;

	game.game_loop();

	return 0;
}