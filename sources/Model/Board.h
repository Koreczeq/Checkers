#pragma once

#include <list>
#include <vector>

#define BOARD_SIZE 8


enum class SquareState {black, white, empty};

struct Square
{
	int posX;
	int posY;
	SquareState state;
};

class Board {
	void setBoard();
public:
	std::vector<std::vector<Square>> squares;
	Board();
};