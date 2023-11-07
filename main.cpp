#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Cannon.h"
#include "Ball.h"

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    Cannon cannon(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)); // Création d'un objet Canon

    Ball ball(400, 300, 10); // Création d'une balle

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        //gameObject.setX(168);
        //gameObject.setY(200);


        cannon.update(window); // Mettre à jour l'angle du canon selon la souris
        cannon.draw(window); // Dessiner le canon

        ball.update(window); // Mettre à jour la position de la balle
        ball.draw(window); // Dessiner la balle


        window.display();
    }

    return 0;
}