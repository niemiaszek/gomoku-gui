#include "Algorithm.h"

Algorithm::Algorithm(Board* board, char sign) {
	initial_position_ = nullptr;
	sign_ = sign;
	board_ = board;
	size_ = board->getSize();
	condition_ = board->getCondition();
}	
Algorithm::~Algorithm() {
	board_->deleteRepresentation(initial_position_->representation_);
	
	delete initial_position_;
}
void Algorithm::run() {
	char** representation;
	board_->copyRepresentation(representation);
	initial_position_ = new Position;
	initial_position_->representation_ = representation;
	Move move;
	move.heuristic_score = 0;
	move.acutal_score = 0;
	move.x = -1;
	move.y = -1;
	initial_position_->valid_moves = getValidMoves(representation);
	execution();
}

void Algorithm::updateCandidateMoves(std::pair<int, int> last_update, std::set<std::pair<int, int>>& candidate_moves, char** representation) {
	int x = last_update.first;
	int y = last_update.second;
	int breadth = 2;
	if (x < breadth)
		x = breadth;
	else if (x > size_ - breadth)
		x = size_ - breadth;
	if (y < breadth)
		y = breadth;
	else if (y > size_ - breadth)
		y = size_ - breadth;

	for(int i = x - breadth; i <= x + breadth; i++)
		for (int j = y - breadth; j <= y + breadth; j++) {
			if (representation[i][j] != ' ')
				continue;
			std::pair<int, int> candidate(i, j);
			candidate_moves.emplace(candidate);
		}
	candidate_moves.erase(last_update);
}

std::pair<int, int> Algorithm::getBestMove() {
	return std::pair<int, int>(initial_position_->current_move.x, initial_position_->current_move.y);
}
std::vector<Move> Algorithm::getValidMoves(char** representation) {
	std::vector<Move> valid_moves;
	int size = board_->getSize();
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (representation[i][j] == ' ') {
				Move move;
				move.x = i;
				move.y = j;
				valid_moves.push_back(move);
			}
		}
	return valid_moves;
}

int Algorithm::evaluateBoard(char** representation, char player) {
	int evaluation_score = 0;
	int winning_reward = 10000;
	int i, j, l;
	for (i = 0; i < size_; i++) { // checking every row and column
		l = 0;
		for (j = 0; j < size_; j++) {
			if (j == 0 && representation[i][j] != ' ') // if it's starting column and if it's taken by player
				l++;
			if (j > 0 && representation[i][j - l] == representation[i][j] && representation[i][j] != ' ') // if previous position is same as current and it's not empty
				l++;
			else if (j > 0 && representation[i][j - 1] != representation[i][j]) // if previous is position is different than current
				l = 0;
			if (j > 0 && l == 0 && representation[i][j] != ' ') // if this position is taken
				l++;

			if (l > 0 && representation[i][j] == player)
				evaluation_score += l * l;

			if (l == condition_) { // when condition to win is reached, check if there are no more in row, which ruins condition
				if (j == size_ - 1) { // edge condition, last element in table. Used to avoid accessing out of range element
					evaluation_score += winning_reward;
				}
				else if (representation[i][j + 1] != representation[i][j - 1]) { // if there are more than condition in row
					evaluation_score += winning_reward;
				}
			}
		}
	}

	for (j = 0; j < size_; j++) { // checking every row and column
		l = 0;
		for (i = 0; i < size_; i++) {
			if (i == 0 && representation[i][j] != ' ') // if it's starting column and if it's taken by player
				l++;
			if (i > 0 && representation[i - 1][j] == representation[i][j] && representation[i][j] != ' ') // if previous position is same as current and it's not empty
				l++;
			else if (i > 0 && representation[i - 1][j] != representation[i][j]) // if previous is position is different than current
				l = 0;
			if (i > 0 && l == 0 && representation[i][j] != ' ') // if this position is taken
				l++;

			if (l > 0 && representation[i][j] == player)
				evaluation_score += l * l;

			if (l == condition_) { // when condition to win is reached, check if there are no more in row, which ruins condition
				if (i == size_ - 1) { // edge condition, last element in table. Used to avoid accessing out of range element
					evaluation_score += winning_reward;
				}
				else if (representation[i + 1][j] != representation[i - 1][j]) { // if there are more than condition in row
					evaluation_score += winning_reward;
				}
			}
		}
	}

	for (i = 0; i < size_ - 1; i++) { // diagonals pararell to line ([14][0], [0][14]), left side, botton to top;
		l = 0;
		for (j = 0; j <= i; j++) {
			if (j == 0 && representation[i - j][j] != ' ')
				l++;
			if (j > 0 && representation[i + 1 - j][j - 1] == representation[i - j][j] && representation[i - j][j] != ' ')
				l++;
			else if (j > 0 && representation[i + 1 - j][j - 1] != representation[i - j][j])
				l = 0;
			if (j > 0 && l == 0 && representation[i - j][j] != ' ')
				l++;

			if (l > 0 && representation[i - j][j] == player)
				evaluation_score += l * l;

			if (l == condition_) {
				if (j == i && i != 0) {
					evaluation_score += winning_reward;
				}
				else if (representation[i + 1 - j][j - 1] != representation[i - 1 - j][j + 1]) {
					evaluation_score += winning_reward;
				}
			}
		}
	}

	for (i = 0; i < size_; i++) { // pararell to ([14][0], [0][14]), right side, top to bottom
		l = 0;
		for (j = size_ - 1; j >= i; j--) {
			if (j == size_ - 1 && representation[size_ - 1 - j + i][j] != ' ')
				l++;
			if (j < size_ - 1 && representation[size_ - 1 - j + i][j] == representation[size_ - 1 - j - 1 + i][j + 1] && representation[size_ - 1 - j + i][j] != ' ')
				l++;
			else if (j < size_ - 1 && representation[size_ - 1 - j - 1 + i][j + 1] != representation[size_ - 1 - j + i][j])
				l = 0;
			if (j < size_ - 1 && l == 0 && representation[size_ - 1 - j + i][j] != ' ')
				l++;

			if (l > 0 && representation[size_ - 1 - j + i][j] == player)
				evaluation_score += l * l;

			if (l == condition_) {
				if (j == i) {
					evaluation_score += winning_reward;
				}
				else if (representation[size_ - 1 - j - 1 + i][j + 1] != representation[size_ - 1 - j + 1 + i][j - 1]) {
					evaluation_score += winning_reward;
				}
			}
		}
	}

	for (i = 0; i < size_; i++) { // pararell to ([0][0], [14][14]), left side, top to bottom
		l = 0;
		for (j = 0; j < size_ - i; j++) {
			if (j == 0 && representation[i + j][j] != ' ')
				l++;
			if (j > 0 && representation[i + j - 1][j - 1] == representation[i + j][j] && representation[i + j][j] != ' ')
				l++;
			else if (j > 0 && representation[i + j - 1][j - 1] != representation[i + j][j])
				l = 0;
			if (j > 0 && l == 0 && representation[i + j][j] != ' ')
				l++;

			if (l > 0 && representation[i+j][j] == player)
				evaluation_score += l * l;

			if (l == condition_) {
				if ((i + j + 1) == size_) {
					evaluation_score += winning_reward;
				}
				else if (representation[i + j + 1][j + 1] != representation[i + j - 1][j - 1]) {
					evaluation_score += winning_reward;
				}
			}
		}
	}

	for (j = 1; j < size_; j++) { // pararell to ([0][0], [14][14]), right side, top to bottom{
		l = 0;
		for (i = 0; i < size_ - j; i++) {
			if (i == 0 && representation[i][j + i] != ' ')
				l++;
			if (i > 0 && representation[i - 1][j + i - 1] == representation[i][j + i] && representation[i][j + i] != ' ')
				l++;
			else if (i > 0 && representation[i - 1][j + i - 1] != representation[i][j + i])
				l = 0;
			if (i > 0 && l == 0 && representation[i][j + i] != ' ')
				l++;

			if (l > 0  && representation[i][j+j] == player)
				evaluation_score += l * l;

			if (l == condition_) {
				if (j + i + 1 == size_) {
					evaluation_score += winning_reward;
				}
				else if (representation[i + 1][j + i + 1] != representation[i - 1][j + i - 1]) {
					evaluation_score += winning_reward;
				}
			}
		}
	}

	return evaluation_score;
}