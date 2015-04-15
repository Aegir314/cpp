#include "Game.h"

/*
TODO:
Dodati start menu sa opcijama new, load, exit
*/
Game::Game() {
	_level.loadLevel("Level1.txt");
	_level.print();
}

Game::~Game() {
}

void Game::start() {
	forever {
		_level.getMove();
		_level.moveNPC();
		_level.print();
	}
}