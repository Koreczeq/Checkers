#pragma once
#include "Board.h"
#include <memory>
#include <iostream>
#include <optional>


enum class gameState {chooseWhite, moveWhite, chooseBlack, moveBlack};

class Model {
	std::shared_ptr<Board> board = std::make_shared<Board>();
	void chooseWhite(Square square);
	void moveWhite(Square square);
	void chooseBlack(Square square);
	void moveBlack(Square square);
	bool setMoves(Square square, bool isBlack);
	void addMoves(Square square, bool isBlack);
	void addBeating(Square square, bool isBlack);
	Square choosenChecker;
	std::list<std::pair<Square, bool>> possibleMoves;//bool representing if this move is a beating 
	gameState gameState;

	void showPossibleMoves();

public:
	Model::Model();
	void move(int posX, int posY);
	void startGame();
	std::shared_ptr<Board> getBoard();
};