#pragma once
#include "Level.h"
#define forever for(;;)
class Game {
public:
	Game();
	~Game();
	void start();
private:
	Level _level;
};

