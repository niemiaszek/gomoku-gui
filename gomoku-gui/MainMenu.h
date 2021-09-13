#pragma once
#include "Menu.h"
class MainMenu : public Menu {
public:
	MainMenu(sf::RenderWindow* window, sf::Font* font):Menu(window, font) { menu_state_ = 1; }
	~MainMenu();
private:
	void handleInput(sf::Event event);
	void generateLayout();
};

