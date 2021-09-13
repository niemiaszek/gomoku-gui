#pragma once
#include "Player.h"
#include "Settings.h"
#include "Position.h"
#include "Algorithm.h"
#include "EasyAlgorithm.h"
#include "MediumAlgorithm.h"
#include "HardAlgorithm.h"

class AIPlayer : public Player {
public:
	using Player::Player;
	AIPlayer(sf::Color color, Settings* settings, Board* board) :Player(color) {
		board_ = board;
		settings_ = settings;
		algorithm_ = nullptr;
	}
	~AIPlayer();
	std::pair<int, int> makeMove();
private:
	Algorithm* algorithm_;
	Board* board_;
	Settings* settings_;
};