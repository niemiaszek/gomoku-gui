#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Menu {
public:
	Menu(sf::RenderWindow* window, sf::Font* font);
	virtual ~Menu();
	virtual int run();
	void updateText(std::string key, std::string value);
	sf::RenderWindow* getWindow();
	sf::Drawable* getDrawable(std::string key);
	

protected:
	virtual void generateLayout() = 0;
	virtual void handleInput(sf::Event event) = 0;
	bool isActive_;
	int menu_state_;
	std::map<std::string, sf::Drawable*> drawables_;
	sf::RenderWindow* window_;
	sf::Font* font_;
	sf::Color background_color_;
	sf::Color creamy_color_;
	sf::Color off_white_color_;
	sf::Vector2f tile_rectangle_size_;
	sf::Vector2f tile_rectangle_origin_;
	sf::Vector2f long_rectangle_size_;
	sf::Vector2f long_rectangle_origin_;
};

