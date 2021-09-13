#include "MainMenu.h"
#include <iostream>
MainMenu::~MainMenu() {
}

void MainMenu::generateLayout() {
	// title
	sf::Text* title_text = new sf::Text("GOMOKU", *font_, 60);
	title_text->setFillColor(sf::Color::Black);
	sf::FloatRect title_text_rect = title_text->getLocalBounds();
	title_text->setOrigin(title_text_rect.left + title_text_rect.width / 2.0f,
		title_text_rect.top + title_text_rect.height / 2.0f);
	title_text->setPosition(640.f, 100.f);
	
	// start menu button
	sf::Text* start_text = new sf::Text("START THE GAME", *font_, 40);
	sf::Vector2f start_position(640.f, 400.f);
	start_text->setFillColor(sf::Color::Black);
	sf::FloatRect start_text_rect = start_text->getLocalBounds();
	start_text->setOrigin(start_text_rect.left + start_text_rect.width / 2.0f,
		start_text_rect.top + start_text_rect.height / 2.0f);
	start_text->setPosition(start_position);

	sf::RectangleShape* start_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	start_rectangle->setOrigin(tile_rectangle_origin_);
	start_rectangle->setPosition(start_position);
	start_rectangle->setFillColor(creamy_color_);
	start_rectangle->setOutlineThickness(5.f);
	start_rectangle->setOutlineColor(sf::Color::Black);

	// about menu button
	sf::Text* about_text = new sf::Text("ABOUT", *font_, 40);
	sf::Vector2f about_position(640.f, 500.f);
	about_text->setFillColor(sf::Color::Black);
	sf::FloatRect about_text_rect = about_text->getLocalBounds();
	about_text->setOrigin(about_text_rect.left + about_text_rect.width / 2.0f,
		about_text_rect.top + about_text_rect.height / 2.0f);
	about_text->setPosition(about_position);

	sf::RectangleShape* about_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	about_rectangle->setOrigin(tile_rectangle_origin_);
	about_rectangle->setPosition(about_position);
	about_rectangle->setFillColor(off_white_color_);
	about_rectangle->setOutlineThickness(5.f);
	about_rectangle->setOutlineColor(sf::Color::Black);

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
	drawables_["start_rectangle"] = start_rectangle;
	drawables_["start_text"] = start_text;
	drawables_["about_rectangle"] = about_rectangle;
	drawables_["about_text"] = about_text;
	drawables_["exit_rectangle"] = exit_rectangle;
	drawables_["exit_text"] = exit_text;
}

void MainMenu::handleInput(sf::Event event) {

	if (event.type == sf::Event::Closed) {
		isActive_ = false;
		menu_state_ = 0;
	}
	// cast items to classes derived from Drawables to be able to check if mouse clicked on such item
	sf::Shape* start_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("start_rectangle"));
	sf::Shape* about_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("about_rectangle"));
	sf::Shape* exit_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("exit_rectangle"));

	// handle mouse clicks on buttons
	if (event.type == sf::Event::MouseButtonPressed) {
		if (exit_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 0;	
		}
		if (about_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 2;
		}
		if (start_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 3;
		}
	}
}