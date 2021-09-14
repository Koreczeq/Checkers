
#include "Model.h"

Model::Model()
{
	gameState = gameState::chooseWhite;
}

void Model::startGame()
{
}

void Model::move(int posX, int posY)
{
	int fieldX = (posX - 90) / 78;
	int fieldY = (posY - 90) / 78;
	std::list<Square>::iterator squarePressed = findSquare(fieldX, fieldY);
	switch (gameState) {
	case gameState::chooseWhite:
		chooseWhite(squarePressed);
		break;
	case gameState::moveWhite:
		moveWhite(squarePressed);
		break;
	case gameState::chooseBlack:
		chooseBlack(squarePressed);
		break;
	case gameState::moveBlack:
		moveBlack(squarePressed);
		break;
	default:
		break;
	}
	return;

}

std::list<Square>::iterator Model::findSquare(int x, int y)
{
	for (auto it = (*board).squares.begin(); it != (*board).squares.end(); it++) {
		if ((*it).posX == x && (*it).posY == y)
			return it;
	}
	return (*board).squares.end();
}

void Model::chooseWhite(std::list<Square>::iterator square)
{
	if ((*square).state != SquareState::white)
		return;
	choosenChecker = (*square);
	gameState = gameState::moveWhite;
	return;
}

void Model::moveWhite(std::list<Square>::iterator square)
{
	if ((*square).state != SquareState::empty)
		return;
	for (auto it = (*board).squares.begin(); it != (*board).squares.end(); it++) {
		if ((*it).posX == choosenChecker.posX && (*it).posY == choosenChecker.posY) {
			(*it).state = SquareState::empty;
			(*square).state = SquareState::white;
		}
	}
	gameState = gameState::chooseBlack;
	return;
}

void Model::chooseBlack(std::list<Square>::iterator square)
{
	if ((*square).state != SquareState::black)
		return;
	choosenChecker = (*square);
	gameState = gameState::moveBlack;
	return;
}

void Model::moveBlack(std::list<Square>::iterator square)
{
	if ((*square).state != SquareState::empty)
		return;
	for (auto it = (*board).squares.begin(); it != (*board).squares.end(); it++) {
		if ((*it).posX == choosenChecker.posX && (*it).posY == choosenChecker.posY) {
			(*it).state = SquareState::empty;
			(*square).state = SquareState::black;
		}
	}
	gameState = gameState::chooseWhite;
	return;
}

std::shared_ptr<Board> Model::getBoard()
{
	return board;
}
