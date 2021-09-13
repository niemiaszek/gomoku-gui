#pragma once
#include "Player.h"
#
class HumanPlayer : public Player {
public:
	using Player::Player;
	HumanPlayer(sf::Color color):Player(color) { ; }
	~HumanPlayer();
	std::pair<int, int> makeMove();
};

