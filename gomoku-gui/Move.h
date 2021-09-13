#pragma once

struct Move {
	int x;
	int y;
	int heuristic_score;
	int acutal_score;

	bool operator<(Move other) const {
		return heuristic_score > other.heuristic_score;
	}
};