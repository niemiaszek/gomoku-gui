#include "HumanPlayer.h"
#include "GameMenu.h"

HumanPlayer::~HumanPlayer()
{
}

std::pair<int, int> HumanPlayer::makeMove()
{
	status_ = 0;
	sf::Shape* board_rectangle = dynamic_cast<sf::Shape*>(menu_->getDrawable("0_board_rectangle"));
	GameMenu* menu = dynamic_cast<GameMenu*>(menu_);
	if (event_.type == sf::Event::MouseButtonPressed) {
		sf::RenderWindow* window = menu_->getWindow();
		if (board_rectangle->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
			sf::Vector2i mouse_position = sf::Mouse::getPosition(*window);
			std::pair<int, int> human_move;
			human_move.first = int(round((mouse_position.x - (640.f - 315.f)) / 45)) % 15;
			human_move.second = int(round((mouse_position.y - (450.f - 315.f)) / 45)) % 15;
			if (!menu->isTaken(human_move)) {
				status_ = 1;
				move_ = human_move;
			}
		}
	}
	return move_;
}