#include "AIPlayer.h"

AIPlayer::~AIPlayer(){

}

std::pair<int, int> AIPlayer::makeMove()
{
	status_ = 0;
	int size = board_->getSize();
	int condition = board_->getCondition();
	switch (settings_->getOption("difficulty")) {
	case 0:
		algorithm_ = new EasyAlgorithm(board_, getSign());
		break;
	case 1:
		algorithm_ = new MediumAlgorithm(board_, getSign(), getOpponentSign());
		break;
	case 2:
		algorithm_ = new HardAlgorithm(board_, getSign(), getOpponentSign());
		break;
	}
	algorithm_->run();
	std::pair<int, int> outcome_move = algorithm_->getBestMove();
	if (outcome_move.first >= 0 && outcome_move.second >= 0) {
		status_ = 1;
		std::cout << "success" << std::endl;
	}
	return outcome_move;
}
