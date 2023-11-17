#pragma once
#include "GameObject.h"
#include "Ball.h"
#include "Collider.h"

class Brick : public GameObject {
private:
    sf::RectangleShape shape;
    bool isDestroyed_;
    int health;

public:
    Brick(float x, float y,float width, float height, sf::Color color);

    void draw(sf::RenderWindow& window);
    bool intersects(Ball& otherObject, float bounceAngle);
    sf::FloatRect getGlobalBounds() const;
    std::vector<Brick> createBricks(sf::RenderWindow& window, int rows, int cols, float gap);

    bool isDestroyed() const; // Getter pour la propriété isDestroyed
    void destroy();
};