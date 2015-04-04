#include "Game.h"


Game::Game() {
	_level.loadLevel("Level1.txt");
	_level.print();
}


Game::~Game() {
}
void Game::start() {
	forever{
		_level.print();
	}
}
