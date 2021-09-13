#include "Settings.h"
Settings::Settings() {
	options_ = std::map<std::string, int>();
	options_["mode"] = 0;
	max_options_["mode"] = 2;
	options_["difficulty"] = 0;
	max_options_["difficulty"] = 1;
	options_["starting"] = 0;
	max_options_["starting"] = 1;
	options_["size"] = 15;
	options_["condition"] = 5;

}
Settings::~Settings() {
	options_.clear();
}
void Settings::updateOption(std::string key) {
	int current_value = options_.at(key);
	if (++current_value > max_options_.at(key))
		current_value = 0;
	options_[key] = current_value;
}

int Settings::getOption(std::string key) {
	return options_.at(key);
}
