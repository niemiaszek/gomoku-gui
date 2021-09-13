#include "Game.h"
Game::Game() : menu_state_(1), board_(nullptr), menu_(nullptr), player_1_(nullptr), player_2_(nullptr) {
	window_ = new sf::RenderWindow(sf::VideoMode(1280, 960), "Gomoku");
	window_->setVerticalSyncEnabled(true);
	font_ = new sf::Font();
	if (!font_->loadFromFile("assets/arial.ttf"))
	{
		std::cout << "Error" << std::endl;
	}
	settings_ = new Settings();
}
Game::~Game() {
	window_->close();
	delete window_;
	delete font_;
	delete settings_;
	delete board_;
}
bool Game::run() {
	while (menu_state_) {
		switch (menu_state_) {
		case 1:
			menu_ = new MainMenu(window_, font_);
			break;
		case 2:
			menu_ = new AboutMenu(window_, font_);
			break;
		case 3:
			menu_ = new SettingsMenu(window_, font_, settings_);
			break;
		case 4:
			board_ = new Board(settings_);
			generatePlayers();
			menu_ = new GameMenu(window_, font_, player_1_, player_2_, board_);
			break;
		case 5:
			menu_ = new ExitMenu(window_, font_);
			break;
		default:
			break;
		}
		if (menu_state_ != 6) {
			menu_state_ = menu_->run();
			delete menu_;
		}
		else return 1;
	}
	return 0;
}


void Game::generatePlayers() {
	switch (settings_->getOption("mode")) {
	case 0:
		player_1_ = new HumanPlayer(sf::Color::Black);
		player_2_ = new HumanPlayer(sf::Color::White);
		break;
	
	case 1:
		player_1_ = new HumanPlayer(sf::Color::Black);
		player_2_ = new AIPlayer(sf::Color::White, settings_, board_);
		break;
	case 2:
		player_1_ = new AIPlayer(sf::Color::Black, settings_, board_);
		player_2_ = new AIPlayer(sf::Color::White, settings_, board_);
		break;
	}
	if (settings_->getOption("starting")) {
		Player* tmp = player_1_;
		player_1_ = player_2_;
		player_2_ = tmp;
	}
}
