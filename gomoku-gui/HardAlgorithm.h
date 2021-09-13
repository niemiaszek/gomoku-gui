#pragma once
#include "Algorithm.h"
#include <set>
class HardAlgorithm : public Algorithm{
public:
	HardAlgorithm(Board* board, char player_sign, char opponent_sign) :Algorithm(board, player_sign) {
		executions_ = 0, player_sign_ = player_sign, opponent_sign_ = opponent_sign;
	}
private:
	void execution();
	int negamax();
	void rankMoves(char player_sign, std::vector<Move> &player_moves);

	std::set<Move> candidates;
	int executions_;
	char opponent_sign_;
	char player_sign_;
};

