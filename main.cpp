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

    Cannon cannon(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)); // Cr�ation d'un objet Canon

    Ball ball(400, 300, 10); // Cr�ation d'une balle


    float Angle = 45.0f;

    const int numBricks = 30; // Nombre de briques que vous voulez

    // Cr�ez un tableau de briques
    std::vector<Brick> bricks;
    bricks.reserve(numBricks); // R�servez de l'espace pour les briques


    // Remplissez le tableau de briques
    for (int i = 0; i < numBricks; i++) {
        float x = i * 60.0f; // Ajustez la position des briques selon vos besoins
        float y = 100.0f;

        // G�n�rez une couleur al�atoire
        sf::Color randomColor(
            sf::Uint8(rand() % 256), // Composante rouge al�atoire
            sf::Uint8(rand() % 256), // Composante verte al�atoire
            sf::Uint8(rand() % 256)  // Composante bleue al�atoire
        );

        Brick brick(x, y, randomColor); // Cr�ez une brique
        bricks.push_back(brick); // Ajoutez-la au tableau de briques
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();

        cannon.update(window); // Mettre � jour l'angle du canon selon la souris
        cannon.draw(window); // Dessiner le canon

        ball.update(window); // Mettre � jour la position de la balle
        ball.draw(window); // Dessiner la balle

        // Mettez � jour et dessinez les briques
        for (Brick& brick : bricks) {
            brick.draw(window);

            std::cout << "test brique :" <<brick.intersects(ball, Angle) << std::endl;
            
        }

        window.display();
    }

    return 0;
}