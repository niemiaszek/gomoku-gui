#pragma once
#include <algorithm>
#include <list>
#include <set>
#include <vector>
#include "Move.h"
#include "Board.h"

struct Position{
	std::list<Position> positions;
	std::vector<Move> valid_moves;
	std::set<std::pair<int, int>> candidates;
	Move current_move;
	char** representation_;
};

