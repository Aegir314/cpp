#include "Player.h"


Player::Player() : _x(0), _y(0), _health(100), _experience(0), _lvl(1) {
}


Player::~Player() {
}

int Player::getX() const {

	return _x;

}
int Player::getY() const {
	return _y;
}
void Player::setX(const int x) {
	_x = x;

}
void Player::setY(const int y) {
	_y = y;
}