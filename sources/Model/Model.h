#pragma once
#include "Board.h"
#include <memory>

enum class gameState {chooseWhite, moveWhite, chooseBlack, moveBlack};

class Model {
	std::shared_ptr<Board> board = std::make_shared<Board>();
	std::list<Square>::iterator findSquare(int x, int y);
	void chooseWhite(std::list<Square>::iterator square);
	void moveWhite(std::list<Square>::iterator square);
	void chooseBlack(std::list<Square>::iterator square);
	void moveBlack(std::list<Square>::iterator square);
	gameState gameState;
	Square choosenChecker;
public:
	Model::Model();
	void move(int posX, int posY);
	void startGame();
	std::shared_ptr<Board> getBoard();
};