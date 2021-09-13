#pragma once
#include <map>
#include <iostream>
class Settings {
public:
	Settings();
	~Settings();
	void updateOption(std::string key);
	int getOption(std::string key);

private:
	std::map<std::string, int> options_;
	std::map<std::string, int> max_options_;
};
