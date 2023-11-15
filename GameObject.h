#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
    int posX;
    int posY;
    int lon;
    int lar;
    sf::RectangleShape shape;

public:
    GameObject(int x, int y, int length, int width);

    int getX() const;
    int getY() const;
    int getLength() const;
    int getWidth() const;
    //int getRadius();

    void setX(int x);
    void setY(int y);
    void setLength(int length);
    void setWidth(int width);
    void setPosition(int x, int y);

    void printInfo() const;
    void draw(sf::RenderWindow& window);
    void updatePosition(const sf::RenderWindow& window);
    bool intersects(const GameObject& other) const;

    sf::FloatRect getGlobalBounds() const;
};