#include "Cannon.h"

Cannon::Cannon(float windowWidth, float windowHeight) : GameObject(windowWidth / 2, windowHeight - 5, 100, 10), angle(0) {
    shape.setSize(sf::Vector2f(100, 10)); // Taille du canon
    shape.setFillColor(sf::Color::Red);
    std::vector<float> angles;

    // Positionne le canon centré en bas de la fenêtre
    shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2); // Positionnement de l'origine pour la rotation
    shape.setPosition(windowWidth / 2, windowHeight - shape.getSize().y / 2);

    std::pair<Ball, float> projectile = fire();
    angles.push_back(projectile.second);
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

bool Cannon::isBallFlying() const {
    return isBallInFlight;
}

std::pair<Ball, float> Cannon::fire() {
    if (isBallOnCannon && !isBallInFlight && !isBallOut) {
        float ballRadius = 10.f;
        sf::Vector2f cannonPos = shape.getPosition();
        float radians = angle * 3.14159 / 180.f;

        float x = cannonPos.x + cos(radians) * 50;
        float y = cannonPos.y + sin(radians) * 50;

        sf::Vector2f direction(cos(radians), sin(radians));
        
        Ball projectile(x, y, ballRadius); 
        projectile.setDirection(direction);
        isBallInFlight = true;
        isBallOnCannon = false;
        return std::make_pair(projectile, radians);
    }
    else {
        return std::make_pair(Ball(300, 300, 10), 0.f);
    }
}

void Cannon::resetBallInFlight() {
    isBallInFlight = false;
}

void Cannon::setIsBallOut(bool value) {
    isBallOut = value;
}

void Cannon::resetIsBallOut() {
    isBallOut = false;
}

void Cannon::setIsBallOnCannon(bool value) {
    isBallOnCannon = value;
}

bool Cannon::getIsBallOnCannon() const {
    return isBallOnCannon;
}