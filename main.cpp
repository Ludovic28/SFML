#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"
#include "Cannon.h"
#include "Ball.h"
#include "Collider.h"
#include "Brick.h"
#include <iostream>


using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    Cannon cannon(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)); // Création d'un objet Canon

    Ball ball(300, 300, 10); // Création d'une balle

    std::vector<Ball> projectiles;
    std::vector<float> angles;

    Brick brick(200,200,100,50,sf::Color::Green);
    std::vector<Brick> bricks = brick.createBricks(window, 7, 15, 8);

    float Angle = 45.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();

        if (!cannon.isBallFlying() && sf::Mouse::isButtonPressed(sf::Mouse::Left) && projectiles.empty()) {
            // Tire une nouvelle balle
            std::pair<Ball, float> projectile = cannon.fire();
            projectiles.push_back(projectile.first);
            angles.push_back(projectile.second);
        }

        cannon.update(window); // Mettre à jour l'angle du canon selon la souris
        cannon.draw(window); // Dessiner le canon


        // Mettez à jour et dessinez les briques
        for (Brick& brick : bricks) {
            brick.draw(window);

            brick.intersects(ball, Angle);

            ball.update(window); // Mettre à jour la position de la balle
            
        }


        ball.draw(window); // Dessiner la balle

        window.display();
    }

    return 0;
}