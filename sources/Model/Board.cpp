#include "Board.h"

void Board::setBoard()
{
	squares.empty();
	for(int x = 0; x < BOARD_SIZE; x++) {
		std::vector<Square> temp;
		for (int y = 0; y < BOARD_SIZE; y++) {
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
			temp.push_back(square);
		}
		squares.push_back(temp);
	}
}

Board::Board()
{
	setBoard();
}
