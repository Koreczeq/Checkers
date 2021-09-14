#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../Model/Model.h"

class Controller {
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<Model> model;

public:
	Controller::Controller(std::shared_ptr<sf::RenderWindow> _window, std::shared_ptr<Model> _model);
	void update(sf::Event event);
};