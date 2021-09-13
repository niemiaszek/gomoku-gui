#include "MediumAlgorithm.h"
void MediumAlgorithm::execution() {
	// getting candidates stored from previous turns
	initial_position_->candidates = board_->candidates_;
	std::pair<int, int> last_update = board_->getLastUpdate();
	if (last_update == std::pair<int, int>(-1, -1)) {
		std::pair<int, int> candidate(7, 7);
		initial_position_->candidates.emplace(candidate);
	}
	else
		updateCandidateMoves(last_update, initial_position_->candidates, initial_position_->representation_);

	for (auto candidate : initial_position_->candidates) {
		char** move_representation;
		board_->copyRepresentation(initial_position_->representation_, move_representation);
		move_representation[candidate.first][candidate.second] = sign_;
		int score_player = evaluateBoard(move_representation, sign_);
		move_representation[candidate.first][candidate.second] = opponent_sign_;
		int score_opponent = evaluateBoard(move_representation, opponent_sign_);
		int score = score_player + score_opponent;
		if (score > initial_position_->current_move.heuristic_score) {
			initial_position_->current_move.heuristic_score = score;
			initial_position_->current_move.x = candidate.first;
			initial_position_->current_move.y = candidate.second;
		}
	}
	// update candidates with outcome move
	std::pair<int, int> best_move(initial_position_->current_move.x, initial_position_->current_move.y);
	updateCandidateMoves(best_move, initial_position_->candidates, initial_position_->representation_);
	initial_position_->candidates.erase(std::pair<int, int>(initial_position_->current_move.x, initial_position_->current_move.y));
	board_->candidates_ = initial_position_->candidates;
	std::cout << initial_position_->candidates.size() << std::endl;
}