#include "Board.h"

void Board::setBoard()
{
	squares.empty();
	for(int y = 0; y < BOARD_SIZE; y++) {
		for (int x = y % 2; x < BOARD_SIZE; x++) {
			SquareState state;
			if (x % 2 != y % 2)
				state = SquareState::empty;
			else if (y < BOARD_SIZE / 2 - 1)
				state = SquareState::white;
			else if (y < BOARD_SIZE / 2 + 1)
				state = SquareState::empty;
			else
				state = SquareState::black;
			Square square = { x, y, state };
			squares.push_back(square);
		}
	}
}

Board::Board()
{
	setBoard();
}
