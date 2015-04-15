#include "Level.h"
#include <conio.h>
#include <fstream>

Level::Level() {
}

Level::~Level() {
}

/*
TODO:
random level generation
save game
load game
*/
void Level::loadLevel(std::string levelName) {
	std::ifstream input;
	input.open(levelName);
	if (input.fail()) {
		error("Failed to open file: " + levelName);
	}
	std::string temp = "";
	while (std::getline(input, temp)) {
		_levelLayout.push_back(temp);
	}
	parseLevel();
}

void Level::print() {
	system("CLS");
	for (unsigned i = 0; i < _levelLayout.size(); ++i) {
		printf("%s\n", _levelLayout[i].c_str());
	}
	printf("\n");
}

void Level::parseLevel() {
	for (unsigned int i = 0; i < _levelLayout.size(); ++i) {
		for (unsigned int j = 0; j < _levelLayout[i].size(); ++j) {
			switch (_levelLayout[i][j]) {
			case '@':
				_wolf.setX(j);
				_wolf.setY(i);
				break;
				/*
							TODO:
							Napraviti funkciju koja vraca objekte tipa Enemy
							,racuna statove ovisno o levelu i ko zna cemu

							(member od Enemy ne Level)
							Enemy Enemy::getEnemy(String name, int level) {return Enemy(bla.bla,bla...);}
							_enemies.push_back(std::move(getEnemy("Mage",level)));
							level je neka static varijabla koju postavljamo u load ili parse level
							*/
			case 'M':
				//koristiti move, koristi move overload od push_back, sprijecava extra copy
				_enemies.push_back(std::move(Enemy("Mage", j, i, 70, 8, 40)));
				break;
			case 'W':
				_enemies.push_back(std::move(Enemy("Warlock", j, i, 80, 6, 40)));
				break;
			case 'B':
				_enemies.push_back(std::move(Enemy("Berserker", j, i, 85, 5, 50)));
				break;
			}
		}
	}
}

char Level::getTile(int x, int y) const {
	return _levelLayout[y][x];
}

void Level::setTile(char tile, int x, int y) {
	_levelLayout[y][x] = tile;
}

void Level::getMove() {
	for each (auto i in _enemies) {
		std::printf("%s\n", i.getName().c_str());
	}
	const int x = _wolf.getX();
	const int y = _wolf.getY();
	switch (tolower(_getch())) {
	case 'w':
		if (getTile(x, y - 1) == '.') {
			setTile('.', x, y);
			setTile('@', x, y - 1);
			_wolf.setX(x);
			_wolf.setY(y - 1);
		}
		break;
	case 's':
		if (getTile(x, y + 1) == '.') {
			setTile('.', x, y);
			setTile('@', x, y + 1);
			_wolf.setX(x);
			_wolf.setY(y + 1);
		}
		break;
	case 'a':
		if (getTile(x - 1, y) == '.') {
			setTile('.', x, y);
			setTile('@', x - 1, y);
			_wolf.setX(x - 1);
			_wolf.setY(y);
		}
		break;
	case 'd':
		if (getTile(x + 1, y) == '.') {
			setTile('.', x, y);
			setTile('@', x + 1, y);
			_wolf.setX(x + 1);
			_wolf.setY(y);
		}
		break;
	}
}

void Level::moveNPC() {
	char moveDirection, enemyTile;
	int x, y;
	for (unsigned int i = 0; i < _enemies.size(); i++) {
		moveDirection = _enemies[i].getMove(_wolf);
		enemyTile = _enemies[i].getName()[0];
		x = _enemies[i].getX();
		y = _enemies[i].getY();
		switch (moveDirection) {
		case 'w':
			if (getTile(x, y - 1) == '.') {
				setTile('.', x, y);
				setTile(enemyTile, x, y - 1);
				_enemies[i].setX(x);
				_enemies[i].setY(y - 1);
			}
			break;
		case 's':
			if (getTile(x, y + 1) == '.') {
				setTile('.', x, y);
				setTile(enemyTile, x, y + 1);
				_enemies[i].setX(x);
				_enemies[i].setY(y + 1);
			}
			break;
		case 'a':
			if (getTile(x - 1, y) == '.') {
				setTile('.', x, y);
				setTile(enemyTile, x - 1, y);
				_enemies[i].setX(x - 1);
				_enemies[i].setY(y);
			}
			break;
		case 'd':
			if (getTile(x + 1, y) == '.') {
				setTile('.', x, y);
				setTile(enemyTile, x + 1, y);
				_enemies[i].setX(x + 1);
				_enemies[i].setY(y);
			}
			break;
		default:
			break;
		}
	}
}