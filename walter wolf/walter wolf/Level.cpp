#include "Level.h"

Level::Level() {
}


Level::~Level() {
}
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

}

void Level::print() {
	system("CLS");
	for (unsigned int i = 0; i < _levelLayout.size(); ++i) {
		for (unsigned int j = 0; j < _levelLayout[i].size(); ++j) {
			std::printf("%c", _levelLayout[i][j]);
		}
		std::printf("\n");
	}
}

void Level::parseLevel() {
	for (unsigned int i = 0; i < _levelLayout.size(); ++i) {
		for (unsigned int j = 0; j < _levelLayout[i].size(); ++j) {
			switch (_levelLayout[i][j]) {
				case '@':
					_wolf.setX(j);
					_wolf.setY(i);
					break;
					
			}
		}
		
	}

}

char Level::getTile(int x, int y) const {
	return _levelLayout[y][x];

}
void Level::setTile(const char tile, const int x, const int y) {
	_levelLayout[y][x] = tile;
}









