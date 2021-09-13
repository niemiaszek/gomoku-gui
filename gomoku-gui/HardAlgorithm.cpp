#include "HardAlgorithm.h"
void HardAlgorithm::execution() {
	std::vector<Move> moves_player, moves_opponent, candidate_moves;
	rankMoves(player_sign_, moves_player);
	rankMoves(opponent_sign_, moves_opponent);

}
void HardAlgorithm::rankMoves(char player_sign, std::vector<Move>& player_moves) {

}

int HardAlgorithm::negamax() {
	return 0;
}