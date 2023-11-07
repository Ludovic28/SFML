#pragma once
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Ball {
private:
    float radius; // Rayon de la balle
    CircleShape shape; // Forme de la balle
    Vector2f velocity; // Vitesse de la balle

public:

    Ball(float x, float y, float rad) : radius(rad), velocity(0.25f, -0.25f) {
        shape.setRadius(radius);
        shape.setFillColor(Color::Green);
        shape.setOrigin(radius, radius);
        shape.setPosition(x, y);
    }

    void update(const RenderWindow& window) 
    {

        float speed = 0.25f; // Ajuste la vitesse pour la rendre très lente

        shape.move(velocity * speed); // Déplacement de la balle

        if (shape.getPosition().x - radius < 0 || shape.getPosition().x + radius > window.getSize().x) {
            velocity.x = -velocity.x; // Inverser la direction horizontale
        }
        if (shape.getPosition().y - radius < 0 || shape.getPosition().y + radius > window.getSize().y) {
            velocity.y = -velocity.y; // Inverser la direction verticale
        }
       
    }


    void draw(RenderWindow& window) {
        window.draw(shape);
    }

    // Autres fonctions pour gérer les collisions et le rebond
    // ...
};