#include "GameMenu.h"
#include <cmath>

GameMenu::~GameMenu() {
}

sf::Event GameMenu::getEvent()
{
	return current_event_;
}

sf::RenderWindow* GameMenu::getWindow()
{
	return window_;
}

void GameMenu::generateLayout() {
	// title
	sf::Text* title_text = new sf::Text("PLAYER", *font_, 60);
	title_text->setFillColor(sf::Color::Black);
	sf::FloatRect title_text_rect = title_text->getLocalBounds();
	title_text->setOrigin(title_text_rect.left + title_text_rect.width / 2.0f,
		title_text_rect.top + title_text_rect.height / 2.0f);
	title_text->setPosition(500.f, 80.f);

	// current player color
	sf::Text* player_text = new sf::Text(color_to_string(player_1_->getColor()), *font_, 60);
	player_text->setFillColor(sf::Color::Black);
	sf::FloatRect player_text_rect = player_text->getLocalBounds();
	player_text->setOrigin(player_text_rect.left + player_text_rect.width / 2.0f,
		player_text_rect.top + player_text_rect.height / 2.0f);
	player_text->setPosition(800.f, 80.f);


	// board
	sf::RectangleShape* board_rectangle = new sf::RectangleShape(sf::Vector2f(630.f, 630.f));
	board_rectangle->setOrigin(sf::Vector2f(315.f, 315.f));
	board_rectangle->setPosition(640.f, 450.f);
	board_rectangle->setFillColor(creamy_color_);

	// lines
	for (int i = 0; i < 15; i++) {
		sf::RectangleShape* board_rectangle_vertical = new sf::RectangleShape(sf::Vector2f(3.f, 630.f));
		board_rectangle_vertical->setOrigin(sf::Vector2f(1.5f, 0.f));
		float x_position = (640.f - 315.f) + i*45;
		float y_position = (450.f - 315.f);
		board_rectangle_vertical->setPosition(x_position, y_position);
		board_rectangle_vertical->setFillColor(sf::Color::Black);

		sf::RectangleShape* board_rectangle_horizontal = new sf::RectangleShape(sf::Vector2f(630.f, 3.f));
		board_rectangle_horizontal->setOrigin(sf::Vector2f(1.5f, 0.f));
		x_position = (640.f - 315.f);
		y_position = (450.f - 315.f) + i*45;
		board_rectangle_horizontal->setPosition(x_position, y_position);
		board_rectangle_horizontal->setFillColor(sf::Color::Black);

		std::string rectangle_name_vertical = "1_line_vertical_" + std::to_string(i) + "_rectangle";
		drawables_[rectangle_name_vertical] = board_rectangle_vertical;

		std::string rectangle_name_horizontal = "1_line_horizontal" + std::to_string(i) + "_rectangle";
		drawables_[rectangle_name_horizontal] = board_rectangle_horizontal;
	}

	/// exit button
	sf::Text* exit_text = new sf::Text("QUIT", *font_, 40);
	sf::Vector2f exit_position(640.f, 860.f);
	exit_text->setFillColor(sf::Color::Black);
	sf::FloatRect exit_text_rect = exit_text->getLocalBounds();
	exit_text->setOrigin(exit_text_rect.left + exit_text_rect.width / 2.0f,
		exit_text_rect.top + exit_text_rect.height / 2.0f);
	exit_text->setPosition(exit_position);

	sf::RectangleShape* exit_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	exit_rectangle->setOrigin(tile_rectangle_origin_);
	exit_rectangle->setPosition(exit_position);
	exit_rectangle->setFillColor(creamy_color_);
	exit_rectangle->setOutlineThickness(5.f);
	exit_rectangle->setOutlineColor(sf::Color::Black);

	// Add items to be drawn
	drawables_["title_text"] = title_text;
	drawables_["player_text"] = player_text;

	drawables_["0_board_rectangle"] = board_rectangle;

	drawables_["exit_rectangle"] = exit_rectangle;
	drawables_["exit_text"] = exit_text;
}

void GameMenu::handleInput(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		isActive_ = false;
		menu_state_ = 0;
		return;
	}
	
	sf::Shape* exit_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("exit_rectangle"));
	sf::Shape* board_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("0_board_rectangle"));
	if (event.type == sf::Event::MouseButtonPressed) {
		if (game_outcome_ != 0) {
			isActive_ = false;
			menu_state_ = 5;
			return;
		}
		if (exit_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 0;
			return;
		}
	}
	player_1_->setEvent(event);
	player_1_->setMenu(this);
	std::pair<int, int> outcome_move;
	if(!game_outcome_)
		outcome_move = player_1_->makeMove();
	if (player_1_->getStatus() && !game_outcome_) {
		addStone(outcome_move, player_1_->getColor());
		board_->updateRepresentation(outcome_move.first, outcome_move.second, player_1_->getSign());
		board_->candidates_.erase(outcome_move);
		board_->checkState();
		game_outcome_ = board_->getState();
		if (game_outcome_) 
			changeTitleText();
		else
			changePlayer();
	}
}


bool GameMenu::isTaken(std::pair<int, int> outcome_move) {
	int x = outcome_move.first;
	int y = outcome_move.second;
	float x_position = (640.f - 315.f) + x * 45;
	float y_position = (450.f - 315.f) + y * 45;
	std::string stone_name = "2_stone_" + std::to_string(x) + "_" + std::to_string(y);
	if (drawables_.count(stone_name))
		return true;
	else return false;
}

void GameMenu::addStone(std::pair<int, int> outcome_move, sf::Color stone_color) {
	int x = outcome_move.first;
	int y = outcome_move.second;
	float x_position = (640.f - 315.f) + x * 45;
	float y_position = (450.f - 315.f) + y * 45;
	std::string stone_name = "2_stone_" + std::to_string(x) + "_" + std::to_string(y);
	if (drawables_.count(stone_name)) {
		return;
	}
	sf::CircleShape* stone = new sf::CircleShape(stone_radius_);
	stone->setOrigin(sf::Vector2f(stone_radius_, stone_radius_));
	stone->setPosition(x_position, y_position);
	stone->setFillColor(stone_color);
	stone->setOutlineColor(sf::Color::Black);
	stone->setOutlineThickness(1.f);

	drawables_[stone_name] = stone;
}
void GameMenu::changePlayer() {
	Player* tmp = player_1_;
	player_1_ = player_2_;
	player_2_ = tmp;
	std::string new_text = color_to_string(player_1_->getColor());
	updateText("player_text", new_text);
}

void GameMenu::changeTitleText() {
	if (game_outcome_ == 1) 
		updateText("title_text", "WINNER:");
	else {
		updateText("title_text", "NO");
		updateText("player_text", "WINNER");
	}
}

std::string GameMenu::color_to_string(sf::Color color) {
	if (player_1_->getColor() == sf::Color::Black)
		return "BLACK";
	else return "WHITE";
}