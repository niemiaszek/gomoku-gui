#pragma once
#include "Menu.h"
#include "Settings.h"

class SettingsMenu : public Menu {
public:
	SettingsMenu(sf::RenderWindow* window, sf::Font* font, Settings* settings) :Menu(window, font) { menu_state_ = 3; settings_ = settings; }
	~SettingsMenu();
private:
	Settings *settings_;
	void handleInput(sf::Event event);
	void generateLayout();
};