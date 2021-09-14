#include "View.h"

sf::Texture View::loadTexture(std::string filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	return texture;
}

sf::CircleShape View::createChecker(sf::Color color, int posX, int posY)
{
	sf::CircleShape checker;
	checker.setRadius(35.f);
	checker.setFillColor(color);
	checker.setPosition(95.f + 77.f * posX, 95.f + 77.f * posY);
	return checker;
}

void View::drawCheckers()
{
	for (auto a : whiteCheckers)
		(*window).draw(a);
	for (auto a : blackCheckers)
		(*window).draw(a);
}

void View::setCheckers()
{
	blackCheckers.clear();
	whiteCheckers.clear();
	for (auto a : (*board).squares) {
		if (a.state == SquareState::black)
			blackCheckers.push_back(createChecker(sf::Color::Black, a.posX, a.posY));
		else if (a.state == SquareState::white)
			blackCheckers.push_back(createChecker(sf::Color::White, a.posX, a.posY));
	}
}

View::View(std::shared_ptr<sf::RenderWindow> _window, std::shared_ptr<Model> _model)
{
	window = _window;
	model = _model;
	board = (*model).getBoard();
	setCheckers();
	background = loadTexture("../../../resources/images/board.jpg");

}

void View::update()
{
	sf::Sprite sprite;
	sprite.setTexture(background);
	(*window).clear();
	(*window).draw(sprite);
	setCheckers();
	drawCheckers();
	(*window).display();
}
