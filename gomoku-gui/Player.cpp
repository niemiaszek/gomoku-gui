#include "Player.h"
Player::Player(sf::Color color) : color_(color){
	status_ = 0;
	move_ = std::pair<int, int>(0, 0);
}
Player::~Player() {
}

void Player::setEvent(sf::Event event) {
	event_ = event;
}

void Player::setMenu(Menu* menu) {
	menu_ = menu;
}

int Player::getStatus(){
	return status_;
}

sf::Color Player::getColor()
{
	return color_;
}

char Player::getSign() {
	if (color_ == sf::Color::Black)
		return 'X';
	else return 'O';
}
char Player::getOpponentSign() {
	if (getSign() == 'X')
		return 'O';
	else return 'X';
}