#include "AboutMenu.h"
#include <iostream>


AboutMenu::~AboutMenu() {
}

void AboutMenu::generateLayout() {
	// title
	sf::Text* title_text = new sf::Text("ABOUT", *font_, 60);
	title_text->setFillColor(sf::Color::Black);
	sf::FloatRect title_text_rect = title_text->getLocalBounds();
	title_text->setOrigin(title_text_rect.left + title_text_rect.width / 2.0f,
		title_text_rect.top + title_text_rect.height / 2.0f);
	title_text->setPosition(640.f, 100.f);

	// About text
	sf::Text* about_text = new sf::Text("Game Developed by Patryk Niemiec", *font_, 40);
	sf::Vector2f about_position(640.f, 400.f);
	about_text->setFillColor(sf::Color::Black);
	sf::FloatRect about_text_rect = about_text->getLocalBounds();
	about_text->setOrigin(about_text_rect.left + about_text_rect.width / 2.0f,
		about_text_rect.top + about_text_rect.height / 2.0f);
	about_text->setPosition(about_position);

	// Github URL to project which opens default web browsers with repo
	sf::Text* github_text = new sf::Text("@ https://github.com/niemiaszek/gomoku-gui", *font_, 40);
	github_text->setStyle(sf::Text::Underlined);
	sf::Vector2f github_position(640.f, 450.f);
	github_text->setFillColor(sf::Color::Blue);
	sf::FloatRect github_text_rect = github_text->getLocalBounds();
	github_text->setOrigin(github_text_rect.left + github_text_rect.width / 2.0f,
		github_text_rect.top + github_text_rect.height / 2.0f);
	github_text->setPosition(github_position);

	// Back button
	sf::Text* back_text = new sf::Text("BACK", *font_, 40);
	sf::Vector2f back_position(640.f, 800.f);
	back_text->setFillColor(sf::Color::Black);
	sf::FloatRect back_text_rect = back_text->getLocalBounds();
	back_text->setOrigin(back_text_rect.left + back_text_rect.width / 2.0f,
		back_text_rect.top + back_text_rect.height / 2.0f);
	back_text->setPosition(back_position);

	sf::RectangleShape* back_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	back_rectangle->setOrigin(tile_rectangle_origin_);
	back_rectangle->setPosition(back_position);
	back_rectangle->setFillColor(creamy_color_);
	back_rectangle->setOutlineThickness(5.f);
	back_rectangle->setOutlineColor(sf::Color::Black);

	// Add items to be drawn
	drawables_["title_text"] = title_text;
	drawables_["about_text"] = about_text;
	drawables_["github_text"] = github_text;
	drawables_["back_rectangle"] = back_rectangle;
	drawables_["back_text"] = back_text;
}

void AboutMenu::handleInput(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		isActive_ = false;
		menu_state_ = 0;
	}

	sf::Shape* back_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("back_rectangle"));
	sf::Text* github_text = dynamic_cast<sf::Text*>(drawables_.at("github_text"));
	if (event.type == sf::Event::MouseButtonPressed) {
		if (back_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 1;
		}
		if (github_text->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			system("start https://github.com/niemiaszek/gomoku-gui");
		}
	}
}