#pragma once
#include <SFML/Graphics.hpp>

#include "GameObject.h"


class Cannon {
private:

    int posX;
    int posY;
    int windowWidth = 1600;
    int windowHeight = 900;
    float angle; // Angle de rotation du canon
    RectangleShape shape; // Forme du canon

public:
    Cannon(float windowWidth, float windowHeight) : angle(0) {
        shape.setSize(Vector2f(100, 10)); // Taille du canon
        shape.setFillColor(Color::Red);

        // Positionne le canon centré en bas de la fenêtre
        shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2); // Positionnement de l'origine pour la rotation
        shape.setPosition(windowWidth / 2, windowHeight - shape.getSize().y / 2);
    }

    void update(const RenderWindow& window) {
        Vector2i mousePosition = Mouse::getPosition(window);
        Vector2f worldPos = window.mapPixelToCoords(mousePosition);

        // Calcul de l'angle entre le canon et la position de la souris
        float angle = atan2(worldPos.y - shape.getPosition().y, worldPos.x - shape.getPosition().x);
        angle = angle * 180 / 3.14159; // Conversion en degrés


        shape.setRotation(angle); // Rotation du canon
    }

    void draw(RenderWindow& window) {
        window.draw(shape);
    }
};