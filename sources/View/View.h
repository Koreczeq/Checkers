#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include "../Model/Model.h"

class View {
	std::shared_ptr<sf::RenderWindow> window;
	sf::Texture background;
	std::list<sf::CircleShape> whiteCheckers;
	std::list<sf::CircleShape> blackCheckers;
	std::shared_ptr<Model> model;
	std::shared_ptr<Board> board;
	sf::Texture loadTexture(std::string filename);
	sf::CircleShape createChecker(sf::Color color, int posX, int posY);
	void drawCheckers();
	void setCheckers();
public:
	View::View(std::shared_ptr<sf::RenderWindow> _window, std::shared_ptr<Model> _model);
	void update();

};