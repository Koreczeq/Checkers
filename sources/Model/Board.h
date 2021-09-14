#pragma once

#include <list>

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
	std::list<Square> squares;
	Board();
};