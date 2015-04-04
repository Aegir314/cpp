#include "Error.h"
#include <fstream>
#include <vector>
#include "Player.h"
#pragma once
class Level {
public:
	Level();
	~Level();
	void loadLevel(std::string levelName);
	void print(); 
	void parseLevel();
	char getTile(int x, int y) const;
	void setTile(const char tile, const int x, const int y);


private:
	std::vector<std::string> _levelLayout;
	Player _wolf;
};

