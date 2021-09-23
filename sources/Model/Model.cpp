
#include "Model.h"

Model::Model()
{
	gameState = gameState::chooseWhite;
}

void Model::startGame()
{
}

std::shared_ptr<Board> Model::getBoard()
{
	return board;
}

void Model::move(int posX, int posY)
{
	std::cout << "posX:" << posX << " posY:" << posY << std::endl;
	int fieldX = (posX - 90) / 78;
	int fieldY = (posY - 90) / 78;
	std::cout << "posX:" << fieldX << " posY:" << fieldY  << std::endl;
	if (fieldX < 0 || fieldX >= 8 || fieldY < 0 || fieldY >= 8)
		return;
	Square square{ fieldX, fieldY, (*board).squares[fieldX][fieldY].state };
	switch (gameState) {
	case gameState::chooseWhite:
		chooseWhite(square);
		break;
	case gameState::moveWhite:
		moveWhite(square);
		break;
	case gameState::chooseBlack:
		chooseBlack(square);
		break;
	case gameState::moveBlack:
		moveBlack(square);
		break;
	default:
		break;
	}
	return;

}

void Model::chooseWhite(Square square)
{
	if (square.state != SquareState::white) {
		std::cout << "Wrong pick! Choose white checker!" << std::endl;
		return;
	}
	else if (!setMoves(square, false)) {
		std::cout << "This checker can't move! Choose onother one!" << std::endl;
		return;
	}
	choosenChecker = square;
	gameState = gameState::moveWhite;
	return;
}

void Model::moveWhite(Square square)
{
	showPossibleMoves();
	std::optional<std::pair<Square, bool>> temp;
	for (auto a : possibleMoves) {
		if (a.first.posX == square.posX && a.first.posY == square.posY) {
			Square s = { a.first.posX,a.first.posY,a.first.state };
			temp = std::make_pair(s, a.second);
			std::cout << "Succes!!" << std::endl;
			break;
		}
	}
	if (!temp) {
		std::cout << "this checker can't move there, chose possible move!" << std::endl;
		return;
	}
	if (temp.value().second == false) {
		(*board).squares[choosenChecker.posX][choosenChecker.posY].state = SquareState::empty;
		(*board).squares[square.posX][square.posY].state = SquareState::white;
	}
	else {
		int beatenX = (choosenChecker.posX + square.posX) / 2;
		int beatenY = (choosenChecker.posY + square.posY) / 2;
		(*board).squares[choosenChecker.posX][choosenChecker.posY].state = SquareState::empty;
		(*board).squares[beatenX][beatenY].state = SquareState::empty;
		(*board).squares[square.posX][square.posY].state = SquareState::white;
	}
	gameState = gameState::chooseBlack;
	return;
}

void Model::chooseBlack(Square square)
{
	if (square.state != SquareState::black) {
		std::cout << "Wrong pick! Choose black checker!" << std::endl;
		return;
	}
	else if (!setMoves(square, true)) {
		std::cout << "This checker can't move! Choose onother one!" << std::endl;
		return;
	}
	choosenChecker = square;
	gameState = gameState::moveBlack;
	return;
}

void Model::moveBlack(Square square)
{
	showPossibleMoves();
	std::optional<std::pair<Square, bool>> temp;
	for (auto a : possibleMoves) {
		if (a.first.posX == square.posX && a.first.posY == square.posY) {
			Square s = { a.first.posX,a.first.posY,a.first.state };
			temp = std::make_pair(s, a.second);
			std::cout << "Succes!!" << std::endl;
			break;
		}
	}
	if (!temp) {
		std::cout << "this checker can't move there, chose possible move!" << std::endl;
		return;
	}
	if (temp.value().second == false) {
		(*board).squares[choosenChecker.posX][choosenChecker.posY].state = SquareState::empty;
		(*board).squares[square.posX][square.posY].state = SquareState::black;
	}
	else {
		int beatenX = (choosenChecker.posX + square.posX) / 2;
		int beatenY = (choosenChecker.posY + square.posY) / 2;
		(*board).squares[choosenChecker.posX][choosenChecker.posY].state = SquareState::empty;
		(*board).squares[beatenX][beatenY].state = SquareState::empty;
		(*board).squares[square.posX][square.posY].state = SquareState::black;
	}
	gameState = gameState::chooseWhite;
	return;
}

bool Model::setMoves(Square square, bool isBlack)
{
	possibleMoves.clear();
	addMoves(square, isBlack);
	addBeating(square, isBlack);
	if (possibleMoves.empty())
		return false;
	return true;
}

void Model::addMoves(Square square, bool isBlack)
{
	if (isBlack) {
		if (square.posY <= 0)
			return;
	}
	else {
		if (square.posY >= 7)
			return;
	}
	if (square.posX >= 1 && square.posY < 7 && (*board).squares[square.posX - 1][square.posY + 1 - 2*isBlack].state == SquareState::empty) {
		Square tmp{ square.posX - 1, square.posY + 1 - 2 * isBlack, SquareState::empty };
		std::pair<Square, bool> move = std::make_pair(tmp, false);
		possibleMoves.push_back(move);
	}
	if (square.posX < 7 && square.posY < 7 && (*board).squares[square.posX + 1][square.posY + 1 - 2 * isBlack].state == SquareState::empty) {
		Square tmp{ square.posX + 1, square.posY + 1 - 2 * isBlack, SquareState::empty };
		std::pair<Square, bool> move = std::make_pair(tmp, false);
		possibleMoves.push_back(move);
	}

	return;
}

void Model::addBeating(Square square, bool isBlack)
{
	SquareState colorToBeat;
	if (isBlack) {
		colorToBeat = SquareState::white;
		if (square.posY <= 1)
			return;
	}	
	else {
		colorToBeat = SquareState::black;
		if (square.posY >= 6)
			return;
	}		
	if (square.posX >= 2 && (*board).squares[square.posX - 1][square.posY + 1 - 2 * isBlack].state == colorToBeat) {
		if ((*board).squares[square.posX - 2][square.posY + 2 - 4 * isBlack].state == SquareState::empty) {
			Square tmp{ square.posX - 2, square.posY + 2 - 4 * isBlack, SquareState::empty };
			std::pair<Square, bool> move = std::make_pair(tmp, true);
			possibleMoves.push_back(move);
		}
	}
		
	if (square.posX < 7 && (*board).squares[square.posX + 1][square.posY + 1 - 2 * isBlack].state == colorToBeat) {
		if ((*board).squares[square.posX + 2][square.posY + 2 - (4 * isBlack)].state == SquareState::empty) {
			Square tmp{ square.posX + 2, square.posY + 2 - 4 * isBlack, SquareState::empty };
			std::pair<Square, bool> move = std::make_pair(tmp, true);
			possibleMoves.push_back(move);
		}
	}
	return;
}

void Model::showPossibleMoves() {
	for (auto a : possibleMoves) {
		std::cout << "posX: " << a.first.posX << " posY: " << a.first.posY << " isBeating: " << a.second << std::endl;
	}
}
