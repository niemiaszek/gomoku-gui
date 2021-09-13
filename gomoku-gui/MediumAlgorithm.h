#pragma once
#include "Algorithm.h"
class MediumAlgorithm : public Algorithm {
public:
	MediumAlgorithm(Board* board, char player_sign, char opponent_sign) :Algorithm(board, player_sign) {
		opponent_sign_ = opponent_sign;
	}
	void execution();
private:
	char opponent_sign_;
};

