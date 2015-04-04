#pragma once

class Player {
public:
	Player();
	~Player();
	int getX() const;
	int getY() const;
	void setX(const int x);
	void setY(const int y);
	
private:
	int _x;
	int _y;
	int _health;
	int _damage;
	int _experience;
	int _lvl;
};

