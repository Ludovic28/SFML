#pragma once
#include "GameObject.h"
#include "Ball.h"

class Cannon : public GameObject {
private:
    float angle; // Angle de rotation du canon
    sf::RectangleShape shape; // Forme du canon
    bool isBallInFlight;
    bool isBallOut;
    bool isBallOnCannon;

public:
    Cannon(float windowWidth, float windowHeight);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isBallFlying() const;
    std::pair<Ball, float> fire();
    void resetBallInFlight();
    void setIsBallOut(bool value);
    void resetIsBallOut();
    void setIsBallOnCannon(bool value);
    bool getIsBallOnCannon() const;
};