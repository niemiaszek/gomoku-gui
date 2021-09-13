#pragma once
#include "Menu.h"
#include "Board.h"

class Player {
public:
	Player(sf::Color color);
	virtual ~Player();
	virtual std::pair<int, int> makeMove() = 0;
	virtual void setEvent(sf::Event event);
	virtual void setMenu(Menu* menu);
	virtual int getStatus();
	virtual sf::Color getColor();
	char getSign();
	char getOpponentSign();

protected:
	Menu* menu_;
	sf::Event event_;
	sf::Color color_;
	int status_;
	std::pair<int, int> move_;
};

