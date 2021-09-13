#pragma once
#include "Menu.h"
class ExitMenu : public Menu {
public:
	ExitMenu(sf::RenderWindow* window, sf::Font* font) :Menu(window, font) { menu_state_ = 5; }
	~ExitMenu();
private:
	void handleInput(sf::Event event);
	void generateLayout();
};

