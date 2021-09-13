#include "ExitMenu.h"
#include <iostream>
ExitMenu::~ExitMenu() {
}

void ExitMenu::generateLayout() {
	// title
	sf::Text* title_text = new sf::Text("GOOD GAME", *font_, 60);
	title_text->setFillColor(sf::Color::Black);
	sf::FloatRect title_text_rect = title_text->getLocalBounds();
	title_text->setOrigin(title_text_rect.left + title_text_rect.width / 2.0f,
		title_text_rect.top + title_text_rect.height / 2.0f);
	title_text->setPosition(640.f, 100.f);


	// restart button
	sf::Text* restart_text = new sf::Text("RESTART", *font_, 40);
	sf::Vector2f restart_position(640.f, 500.f);
	restart_text->setFillColor(sf::Color::Black);
	sf::FloatRect restart_text_rect = restart_text->getLocalBounds();
	restart_text->setOrigin(restart_text_rect.left + restart_text_rect.width / 2.0f,
		restart_text_rect.top + restart_text_rect.height / 2.0f);
	restart_text->setPosition(restart_position);

	sf::RectangleShape* restart_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	restart_rectangle->setOrigin(tile_rectangle_origin_);
	restart_rectangle->setPosition(restart_position);
	restart_rectangle->setFillColor(off_white_color_);
	restart_rectangle->setOutlineThickness(5.f);
	restart_rectangle->setOutlineColor(sf::Color::Black);

	/// exit button
	sf::Text* exit_text = new sf::Text("QUIT", *font_, 40);
	sf::Vector2f exit_position(640.f, 600.f);
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
	drawables_["restart_rectangle"] = restart_rectangle;
	drawables_["restart_text"] = restart_text;
	drawables_["exit_rectangle"] = exit_rectangle;
	drawables_["exit_text"] = exit_text;
}

void ExitMenu::handleInput(sf::Event event) {

	if (event.type == sf::Event::Closed) {
		isActive_ = false;
		menu_state_ = 0;
	}
	// cast items to classes derived from Drawables to be able to check if mouse clicked on such item
	sf::Shape* restart_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("restart_rectangle"));
	sf::Shape* exit_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("exit_rectangle"));

	// handle mouse clicks on buttons
	if (event.type == sf::Event::MouseButtonPressed) {
		if (exit_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 0;
		}
		if (restart_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 6;
		}
	}
}