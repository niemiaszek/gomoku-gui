#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MainMenu.h"
#include "AboutMenu.h"
#include "SettingsMenu.h"
#include "GameMenu.h"
#include "ExitMenu.h"
#include "Settings.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

class Game {
public:
	Game();
	~Game();
	bool run();

private:
	void generatePlayers();
	int menu_state_;
	sf::RenderWindow* window_;
	sf::Font* font_;
	Menu* menu_;
	Settings* settings_;
	Player* player_1_;
	Player* player_2_;
	Board* board_;
};