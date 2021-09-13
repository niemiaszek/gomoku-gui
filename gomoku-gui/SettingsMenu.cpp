#include "SettingsMenu.h"

SettingsMenu::~SettingsMenu() {
}

void SettingsMenu::generateLayout() {
	// title
	sf::Text* title_text = new sf::Text("SETTINGS", *font_, 60);
	title_text->setFillColor(sf::Color::Black);
	sf::FloatRect title_text_rect = title_text->getLocalBounds();
	title_text->setOrigin(title_text_rect.left + title_text_rect.width / 2.0f,
		title_text_rect.top + title_text_rect.height / 2.0f);
	title_text->setPosition(640.f, 100.f);

	// mode change button
	sf::Vector2f mode_position(640.f, 400.f);
	sf::RectangleShape* mode_rectangle = new sf::RectangleShape(long_rectangle_size_);
	mode_rectangle->setOrigin(long_rectangle_origin_);
	mode_rectangle->setPosition(mode_position);
	mode_rectangle->setFillColor(creamy_color_);
	mode_rectangle->setOutlineThickness(5.f);
	mode_rectangle->setOutlineColor(sf::Color::Black);

	sf::Text* mode_text = new sf::Text("GAME MODE", *font_, 40);
	mode_text->setFillColor(sf::Color::Black);
	sf::FloatRect mode_text_rect = mode_text->getLocalBounds();
	mode_text->setOrigin(0,
		mode_text_rect.top + mode_text_rect.height / 2.0f);
	mode_text->setPosition(mode_position+sf::Vector2f(-350, 0));
	
	sf::Text* mode_text_option = new sf::Text("HUMAN VS HUMAN", *font_, 40);
	mode_text_option->setFillColor(sf::Color::Black);
	sf::FloatRect mode_text_option_rect = mode_text_option->getLocalBounds();
	mode_text_option->setOrigin(0,
		mode_text_option_rect.top + mode_text_option_rect.height / 2.0f);
	mode_text_option->setPosition(mode_position);

	// difficulty change button
	sf::Vector2f difficulty_position(640.f, 500.f);
	sf::RectangleShape* difficulty_rectangle = new sf::RectangleShape(long_rectangle_size_);
	difficulty_rectangle->setOrigin(long_rectangle_origin_);
	difficulty_rectangle->setPosition(difficulty_position);
	difficulty_rectangle->setFillColor(off_white_color_);
	difficulty_rectangle->setOutlineThickness(5.f);
	difficulty_rectangle->setOutlineColor(sf::Color::Black);

	sf::Text* difficulty_text = new sf::Text("AI DIFFICULTY", *font_, 40);
	difficulty_text->setFillColor(sf::Color::Black);
	sf::FloatRect difficulty_text_rect = difficulty_text->getLocalBounds();
	difficulty_text->setOrigin(0,
		difficulty_text_rect.top + difficulty_text_rect.height / 2.0f);
	difficulty_text->setPosition(difficulty_position + sf::Vector2f(-350, 0));

	sf::Text* difficulty_text_option = new sf::Text("EASY", *font_, 40);
	difficulty_text_option->setFillColor(sf::Color::Black);
	sf::FloatRect difficulty_text_option_rect = difficulty_text_option->getLocalBounds();
	difficulty_text_option->setOrigin(0,
		difficulty_text_option_rect.top + difficulty_text_option_rect.height / 2.0f);
	difficulty_text_option->setPosition(difficulty_position);

	// starting player change button
	sf::Vector2f starting_position(640.f, 600.f);
	sf::RectangleShape* starting_rectangle = new sf::RectangleShape(long_rectangle_size_);
	starting_rectangle->setOrigin(long_rectangle_origin_);
	starting_rectangle->setPosition(starting_position);
	starting_rectangle->setFillColor(creamy_color_);
	starting_rectangle->setOutlineThickness(5.f);
	starting_rectangle->setOutlineColor(sf::Color::Black);

	sf::Text* starting_text = new sf::Text("STARTING", *font_, 40);
	starting_text->setFillColor(sf::Color::Black);
	sf::FloatRect starting_text_rect = starting_text->getLocalBounds();
	starting_text->setOrigin(0,
		starting_text_rect.top + starting_text_rect.height / 2.0f);
	starting_text->setPosition(starting_position + sf::Vector2f(-350, 0));

	sf::Text* starting_text_option = new sf::Text("PLAYER 1", *font_, 40);
	starting_text_option->setFillColor(sf::Color::Black);
	sf::FloatRect starting_text_option_rect = starting_text_option->getLocalBounds();
	starting_text_option->setOrigin(0,
		starting_text_option_rect.top + starting_text_option_rect.height / 2.0f);
	starting_text_option->setPosition(starting_position);

	// start button
	sf::Text* start_text = new sf::Text("START", *font_, 40);
	sf::Vector2f start_position(640.f, 700.f);
	start_text->setFillColor(sf::Color::Black);
	sf::FloatRect start_text_rect = start_text->getLocalBounds();
	start_text->setOrigin(start_text_rect.left + start_text_rect.width / 2.0f,
		start_text_rect.top + start_text_rect.height / 2.0f);
	start_text->setPosition(start_position);

	sf::RectangleShape* start_rectangle = new sf::RectangleShape(tile_rectangle_size_);
	start_rectangle->setOrigin(tile_rectangle_origin_);
	start_rectangle->setPosition(start_position);
	start_rectangle->setFillColor(off_white_color_);
	start_rectangle->setOutlineThickness(5.f);
	start_rectangle->setOutlineColor(sf::Color::Black);

	// back button
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

	drawables_["mode_text"] = mode_text;
	drawables_["mode_text_option"] = mode_text_option;
	drawables_["mode_rectangle"] = mode_rectangle;

	drawables_["difficulty_text"] = difficulty_text;
	drawables_["difficulty_text_option"] = difficulty_text_option;
	drawables_["difficulty_rectangle"] = difficulty_rectangle;
	
	drawables_["starting_text"] = starting_text;
	drawables_["starting_text_option"] = starting_text_option;
	drawables_["starting_rectangle"] = starting_rectangle;


	drawables_["back_rectangle"] = back_rectangle;
	drawables_["back_text"] = back_text;

	drawables_["start_rectangle"] = start_rectangle;
	drawables_["start_text"] = start_text;
}

void SettingsMenu::handleInput(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		isActive_ = false;
		menu_state_ = 0;
	}

	sf::Text* mode_text_option = dynamic_cast<sf::Text*>(drawables_.at("mode_text_option"));
	sf::Text* difficulty_text_option = dynamic_cast<sf::Text*>(drawables_.at("difficulty_text_option"));
	sf::Text* starting_text_option = dynamic_cast<sf::Text*>(drawables_.at("starting_text_option"));
	sf::Shape* start_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("start_rectangle"));
	sf::Shape* back_rectangle = dynamic_cast<sf::Shape*>(drawables_.at("back_rectangle"));
	if (event.type == sf::Event::MouseButtonPressed) {
		if (back_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 1;
		}
		if (start_rectangle->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			isActive_ = false;
			menu_state_ = 4;
		}
		if (mode_text_option->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			settings_->updateOption("mode");
			std::string updated_setting_name;
			switch (settings_->getOption("mode")) {
			case 0:
				updated_setting_name = "HUMAN VS HUMAN";
				break;
			case 1:
				updated_setting_name = "HUMAN VS AI";
				break;
			case 2:
				updated_setting_name = "AI VS AI";
				break;
			}
			updateText("mode_text_option", updated_setting_name);
		}
		if (difficulty_text_option->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			settings_->updateOption("difficulty");
			std::string updated_setting_name;
			switch (settings_->getOption("difficulty")) {
			case 0:
				updated_setting_name = "EASY";
				break;
			case 1:
				updated_setting_name = "MEDIUM";
				break;
			}
			updateText("difficulty_text_option", updated_setting_name);
		}
		if (starting_text_option->getGlobalBounds().contains(window_->mapPixelToCoords(sf::Mouse::getPosition(*window_)))) {
			settings_->updateOption("starting");
			std::string updated_setting_name;
			switch (settings_->getOption("starting")) {
			case 0:
				updated_setting_name = "PLAYER 1";
				break;
			case 1:
				updated_setting_name = "PLAYER 2";
				break;
			}
			updateText("starting_text_option", updated_setting_name);
		}
	}
}
