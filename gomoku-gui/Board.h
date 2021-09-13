#pragma once
#include <utility>
#include "Settings.h"
#include "Position.h"

class Board
{
public:
	Board(Settings* settings);
	~Board();
	bool isEmpty(char** representation);
	int getState();
	int getSize();
	int getCondition();
	void copyRepresentation(char** representation_from, char**& representation_to);
	void copyRepresentation(char**& representation_to);
	void checkState();
	void updateRepresentation(int x, int y, char sign);
	std::pair<int, int> getLastUpdate();
	std::set<std::pair<int, int>> candidates_;
	void deleteRepresentation(char** representation);

private:
	void prepareRepresentation();
	bool isDraw();
	bool isVertical();
	bool isHorizontal();
	bool isDiagonal();
	Settings* settings_;
	int state_;
	char** representation_;
	std::pair<int, int> last_update_;
	int size_;
	int condition_;
};

