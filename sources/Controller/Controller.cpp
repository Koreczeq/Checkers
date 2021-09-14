#include "Controller.h"

Controller::Controller(std::shared_ptr<sf::RenderWindow> _window, std::shared_ptr<Model> _model)
{
	window = _window;
	model = _model;
}

void Controller::update(sf::Event event)
{
	switch (event.type) {
	case sf::Event::Closed:
		(*window).close();
		break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left)
			(*model).move(event.mouseButton.x, event.mouseButton.y);
		break;
	default:
		break;
	}
}
