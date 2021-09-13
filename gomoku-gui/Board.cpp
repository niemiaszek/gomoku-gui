#include "Board.h"
#include <iostream>
#include <string>
Board::Board(Settings* settings) :  representation_(nullptr), last_update_(-1, -1), settings_(settings) {
	candidates_ = std::set<std::pair<int, int>>();
	size_ = settings->getOption("size");
	condition_ = settings->getOption("condition");
	prepareRepresentation();
}
Board::~Board() {
	deleteRepresentation(representation_);
}

void Board::prepareRepresentation() {
	representation_ = new char* [size_];
	for (int i = 0; i < size_; i++)
	{
		representation_[i] = new char[size_];
	}
	for (int i = 0; i < size_; i++)
		for (int j = 0; j < size_; j++) 
			representation_[i][j] = ' ';

}
void Board::updateRepresentation(int x, int y, char sign) {
	last_update_ = std::pair<int, int>(x, y);
	if (representation_[x][y] == ' ') {
		representation_[x][y] = sign;
	}
}

bool Board::isEmpty(char** representation) {
	for (int i = 0; i < size_; i++)
		for (int j = 0; j < size_; j++)
			if (representation[i][j] != ' ')
				return false;
	return true;

}

std::pair<int, int> Board::getLastUpdate() {
	return last_update_;
}

void Board::deleteRepresentation(char** representation) {
	/*
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < size_; j++)
			std::cout << representation[i][j] << " | ";
		std::cout << std::endl;
	}
	*/
	for (int i = 0; i < size_; i++)
		delete[] representation[i];
	delete[] representation;
	representation = nullptr;
}

int Board::getState() {
	return state_;
}

void Board::copyRepresentation(char** representation_from, char**& representation_to) {
	representation_to = new char* [size_];
	for (int i = 0; i < size_; i++) {
		representation_to[i] = new char[size_];
		for (int j = 0; j < size_; j++) {
			representation_to[i][j] = representation_from[i][j];
		}
	}
}
void Board::copyRepresentation(char**& representation_to) {
	representation_to = new char* [size_];
	for (int i = 0; i < size_; i++) {
		representation_to[i] = new char[size_];
		for (int j = 0; j < size_; j++) {
			representation_to[i][j] = representation_[i][j];
		}
	}
}
int Board::getSize() {
	return size_;
}
int Board::getCondition() {
	return condition_;
}

void Board::checkState() {
	if (isVertical() || isHorizontal() || isDiagonal())
		state_ = 1;
	else if (isDraw())
		state_ = 2;
	else state_ = 0;
}

bool Board::isDraw() {
	int i, j;
	bool is_empty = false;
	for (i = 0; i < size_; i++) 
		for(j=0; j<size_; j++)
			if (representation_[i][j] == ' ')
				is_empty = true;
	return !is_empty;
}

bool Board::isHorizontal() {
	int i, j, l;
	for (i = 0; i < size_; i++) { // checking every row and column
		l = 0;
		for (j = 0; j < size_; j++) {
			if (j == 0 && representation_[i][j] != ' ') // if it's starting column and if it's taken by player
				l++;
			if (j > 0 && representation_[i][j - l] == representation_[i][j] && representation_[i][j] != ' ') // if previous position is same as current and it's not empty
				l++;
			else if (j > 0 && representation_[i][j - 1] != representation_[i][j]) // if previous is position is different than current
				l = 0;
			if (j > 0 && l == 0 && representation_[i][j] != ' ') // if this position is taken
				l++;
			if (l == condition_) { // when condition to win is reached, check if there are no more in row, which ruins condition
				if (j == size_ - 1) { // edge condition, last element in table. Used to avoid accessing out of range element
					return true;
				} 
				else if (representation_[i][j + 1] != representation_[i][j - 1]) { // if there are more than condition in row
					return true;
				}
			}
		}
	}
	return false;
}
bool Board::isVertical() {
	int i, j, l;
	for (j = 0; j < size_; j++) { // checking every row and column
		l = 0;
		for (i = 0; i < size_; i++) {
			if (i == 0 && representation_[i][j] != ' ') // if it's starting column and if it's taken by player
				l++;
			if (i > 0 && representation_[i - 1][j] == representation_[i][j] && representation_[i][j] != ' ') // if previous position is same as current and it's not empty
				l++;
			else if (i > 0 && representation_[i - 1][j] != representation_[i][j]) // if previous is position is different than current
				l = 0;
			if (i > 0 && l == 0 && representation_[i][j] != ' ') // if this position is taken
				l++;
			if (l == condition_) { // when condition to win is reached, check if there are no more in row, which ruins condition
				if (i == size_ - 1) { // edge condition, last element in table. Used to avoid accessing out of range element
					return true;
				}
				else if (representation_[i + 1][j] != representation_[i - 1][j]) { // if there are more than condition in row
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::isDiagonal() {
	int i, j, l;
	for (i = 0; i < size_ - 1; i++) { // diagonals pararell to line ([14][0], [0][14]), left side, botton to top;
		l = 0;
		for (j = 0; j <= i; j++) {
			if (j == 0 && representation_[i - j][j] != ' ')
				l++;
			if (j > 0 && representation_[i + 1 - j][j - 1] == representation_[i - j][j] && representation_[i - j][j] != ' ')
				l++;
			else if (j > 0 && representation_[i + 1 - j][j - 1] != representation_[i - j][j])
				l = 0;
			if (j > 0 && l == 0 && representation_[i - j][j] != ' ')
				l++;
			if (l == condition_) {
				if (j == i && i != 0) {
					return true;
				}
				else if (representation_[i + 1 - j][j - 1] != representation_[i - 1 - j][j + 1]) {
					return true;
				}
			}
		}
	}

	for (i = 0; i < size_; i++) { // pararell to ([14][0], [0][14]), right side, top to bottom
		l = 0;
		for (j = size_ - 1; j >= i; j--) {
			if (j == size_ - 1 && representation_[size_ - 1 - j + i][j] != ' ')
				l++;
			if (j < size_ - 1 && representation_[size_ - 1 - j + i][j] == representation_[size_ - 1 - j - 1 + i][j + 1] && representation_[size_ - 1 - j + i][j] != ' ')
				l++;
			else if (j < size_ - 1 && representation_[size_ - 1 - j - 1 + i][j + 1] != representation_[size_ - 1 - j + i][j])
				l = 0;
			if (j < size_ - 1 && l == 0 && representation_[size_ - 1 - j + i][j] != ' ')
				l++;
			if (l == condition_) {
				if (j == i) {
					return true;
				}
				else if (representation_[size_ - 1 - j - 1 + i][j + 1] != representation_[size_ - 1 - j + 1 + i][j - 1]) {
					return true;
				}
			}
		}
	}

	for (i = 0; i < size_; i++) { // pararell to ([0][0], [14][14]), left side, top to bottom
		l = 0;
		for (j = 0; j < size_ - i; j++) {
			if (j == 0 && representation_[i + j][j] != ' ')
				l++;
			if (j > 0 && representation_[i + j - 1][j - 1] == representation_[i + j][j] && representation_[i + j][j] != ' ')
				l++;
			else if (j > 0 && representation_[i + j - 1][j - 1] != representation_[i + j][j])
				l = 0;
			if (j > 0 && l == 0 && representation_[i + j][j] != ' ')
				l++;
			if (l == condition_) {
				if ((i + j + 1) == size_) {
					return true;
				}
				else if (representation_[i + j + 1][j + 1] != representation_[i + j - 1][j - 1]) {
					return true;
				}
			}
		}
	}

	for (j = 1; j < size_; j++) { // pararell to ([0][0], [14][14]), right side, top to bottom{
		l = 0;
		for (i = 0; i < size_ - j; i++) {
			if (i == 0 && representation_[i][j + i] != ' ')
				l++;
			if (i > 0 && representation_[i - 1][j + i - 1] == representation_[i][j + i] && representation_[i][j + i] != ' ')
				l++;
			else if (i > 0 && representation_[i - 1][j + i - 1] != representation_[i][j + i])
				l = 0;
			if (i > 0 && l == 0 && representation_[i][j + i] != ' ')
				l++;
			if (l == condition_) {
				if (j + i + 1 == size_) {
					return true;
				}
				else if (representation_[i + 1][j + i + 1] != representation_[i - 1][j + i - 1]) {
					return true;
				}
			}
		}
	}

	return false;
}