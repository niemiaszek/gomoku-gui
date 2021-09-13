#pragma once
#include "Menu.h"
#include "Settings.h"
class AboutMenu : public Menu {
public:
	using Menu::Menu;
	AboutMenu(sf::RenderWindow* window, sf::Font* font) :Menu(window, font) { menu_state_ = 2; }
	~AboutMenu();
private:
	void handleInput(sf::Event event);
	void generateLayout();
};