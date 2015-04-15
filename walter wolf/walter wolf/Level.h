#include "Error.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#pragma once
class Level {
public:
	Level();
	~Level();
	void loadLevel(std::string levelName);
	void print();
	void parseLevel();
	char getTile(int x, int y) const;
	void setTile(char tile, int x, int y);
	void getMove();
	void moveNPC();

private:
	std::vector<std::string> _levelLayout;
	std::vector<Enemy> _enemies;
	Player _wolf;
};
