// checkers.cpp : Defines the entry point for the application.
//

#include "checkers.h"
#include "sources/Controller/Controller.h"
#include "sources/View/View.h"
#include "sources/Model/Model.h"
#include <SFML/Graphics.hpp>

int main()
{
    std::shared_ptr<Model> model(new Model());
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(800, 800), "Checkers!"));
    std::unique_ptr<View> view(new View(window, model));
    std::unique_ptr<Controller> controller(new Controller(window, model));

    while ((*window).isOpen())
    {
        sf::Event event;
        while ((*window).pollEvent(event))
        {
            (*controller).update(event);
        }
        (*view).update();
    }

    return 0;
}