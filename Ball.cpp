#include "Ball.h"

Ball::Ball(float x, float y, float rad) : GameObject(x, y, rad * 2, rad * 2), radius(rad), velocity(0.25f, -0.25f) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(radius, radius);
    shape.setPosition(x, y);
}

void Ball::update(const sf::RenderWindow& window) {
    float speed = 0.01f; // Ajuste la vitesse pour la rendre très lente

    shape.move(velocity * speed); // Déplacement de la balle

    if (shape.getPosition().x - radius < 0 || shape.getPosition().x + radius > window.getSize().x) {
        velocity.x = -velocity.x; // Inverser la direction horizontale
    }
    if (shape.getPosition().y - radius < 0 || shape.getPosition().y + radius > window.getSize().y) {
        velocity.y = -velocity.y; // Inverser la direction verticale
    }

    // Normaliser le vecteur de vitesse pour maintenir une vitesse constante
    float length = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (length != 0) {
        velocity.x /= length;
        velocity.y /= length;
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Ball::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Ball::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}

sf::Vector2f Ball::getVelocity() const {
    return velocity;
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

