#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* window, sf::Font* font) : window_(window), font_(font) {
	drawables_ = std::map<std::string, sf::Drawable*>();
	background_color_ = sf::Color(255, 255, 255, 255);
	creamy_color_ = sf::Color(255, 253, 208, 255);
	off_white_color_ = sf::Color(247, 247, 247, 255);
	tile_rectangle_size_ = sf::Vector2f(400.f, 100.f);
	tile_rectangle_origin_ = sf::Vector2f(200.f, 50.f);
	long_rectangle_size_ = sf::Vector2f(800, 100.f);
	long_rectangle_origin_ = sf::Vector2f(400, 50.f);
}

Menu::~Menu() {
	for (auto [key, value] : drawables_) {
		delete value;
	}
	drawables_.clear();
}

int Menu::run() {
	isActive_ = true;
	generateLayout();
	while (isActive_ == true) {
		sf::Event event;
		while (window_->pollEvent(event)) {
			handleInput(event);
		}
		window_->clear(background_color_);
		
		for (const auto [key, value] : drawables_) {
			window_->draw(*value);
		}
		window_->display();
	}
	return menu_state_;
}

void Menu::updateText(std::string key, std::string value) {
	sf::Text* updated_text = dynamic_cast<sf::Text*>(drawables_.at(key));
	updated_text->setString(value);
}

sf::RenderWindow* Menu::getWindow()
{
	return window_;
}

sf::Drawable* Menu::getDrawable(std::string key)
{
	return drawables_.at(key);
}
