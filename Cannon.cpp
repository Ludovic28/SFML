#include "Cannon.h"

Cannon::Cannon(float windowWidth, float windowHeight) : GameObject(windowWidth / 2, windowHeight - 5, 100, 10), angle(0) {
    shape.setSize(sf::Vector2f(100, 10)); // Taille du canon
    shape.setFillColor(sf::Color::Red);

    // Positionne le canon centré en bas de la fenêtre
    shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2); // Positionnement de l'origine pour la rotation
    shape.setPosition(windowWidth / 2, windowHeight - shape.getSize().y / 2);
}

void Cannon::update(const sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePosition);

    // Calcul de l'angle entre le canon et la position de la souris
    float angle = atan2(worldPos.y - shape.getPosition().y, worldPos.x - shape.getPosition().x);
    angle = angle * 180 / 3.14159; // Conversion en degrés

    shape.setRotation(angle); // Rotation du canon
}

void Cannon::draw(sf::RenderWindow& window) {
    window.draw(shape);
}