#pragma once
#include "Menu.h"
#include "Settings.h"
#include "Board.h"
#include "Player.h"

class GameMenu : public Menu {
public:
	GameMenu(sf::RenderWindow* window, sf::Font* font, Player* player_1, Player* player_2, Board* board):Menu(window, font) { 
		menu_state_ = 3; 
		stone_radius_ = 20;
		player_1_ = player_1; 
		player_2_ = player_2; 
		board_ = board;
		current_event_ = sf::Event();
		game_outcome_ = 0;
	}
	~GameMenu();
	sf::Event getEvent();
	sf::RenderWindow* getWindow();
	bool isTaken(std::pair<int, int> outcome_move);

private:
	void handleInput(sf::Event event);
	void generateLayout();
	void addStone(std::pair<int, int> outcome_move, sf::Color stone_color);
	void changePlayer();
	void changeTitleText();
	std::string color_to_string(sf::Color color);
	char color_to_char(sf::Color color);
	int game_outcome_;
	Player* player_1_;
	Player* player_2_;
	float stone_radius_;
	sf::Event current_event_;
	Board* board_;
};