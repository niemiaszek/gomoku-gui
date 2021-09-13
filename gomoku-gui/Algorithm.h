#pragma once
#include "Position.h"
#include "Move.h"

class Algorithm
{
public:
	Algorithm(Board* board, char sign);
	virtual ~Algorithm();
	std::pair<int, int> getBestMove();
	void run();

protected:
	int size_;
	int condition_;
	char sign_;
	void updateCandidateMoves(std::pair<int, int> last_update, std::set<std::pair<int, int>>& candidate_moves, char** representation);
	std::vector<Move> getValidMoves(char** representation);
	int evaluateBoard(char** representation, char player);
	virtual void execution() = 0;
	Position* initial_position_;
	Board* board_;
};

