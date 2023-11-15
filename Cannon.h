#pragma once
#include "GameObject.h"

class Cannon : public GameObject {
private:
    float angle; // Angle de rotation du canon
    sf::RectangleShape shape; // Forme du canon

public:
    Cannon(float windowWidth, float windowHeight);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};