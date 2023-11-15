#pragma once
#include "GameObject.h"
#include "Ball.h"
#include "Collider.h"

class Brick {
private:
    sf::RectangleShape shape;
    bool isDestroyed;

public:
    Brick(float x, float y, sf::Color color);

    void draw(sf::RenderWindow& window);
    bool intersects(Ball& otherObject, float bounceAngle) const;
    sf::FloatRect getGlobalBounds() const;
};