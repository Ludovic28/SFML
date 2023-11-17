#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject {
private:
    float radius;
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool ballIsDestroyed;

public:
    Ball(float x, float y, float rad);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    float getRadius() const {
        return radius;
    }

    sf::FloatRect getGlobalBounds() const;
    void setVelocity(const sf::Vector2f& vel);
    sf::Vector2f getVelocity() const;
    sf::Vector2f getPosition() const;

    void setDirection(const sf::Vector2f& newDirection);

    bool isDestroyed() const;
    void destroy();
};