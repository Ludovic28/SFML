#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class GameObject
{
private:

    int posX;
    int posY;

    int lon;
    int lar;

    RectangleShape shape;


public:
    // Constructeur pour initialiser les propriétés de l'objet
    GameObject(int x, int y, int length, int width)
    {
        this->posX = x;
        this->posY = y;
        this->lon = length;
        this->lar = width;

        shape.setSize(sf::Vector2f(lon, lar));
        shape.setPosition(sf::Vector2f(posX, posY));
        shape.setFillColor(sf::Color::Blue);
    }

    // Méthodes pour obtenir les coordonnées X et Y
    int getX() const {
        return posX;
    }

    int getY() const {
        return posY;
    }

    // Méthodes pour obtenir la longueur et la largeur
    int getLength() const {
        return lon;
    }

    int getWidth() const {
        return lar;
    }

    // Méthodes pour définir les coordonnées X et Y
    void setX(int x) {
        posX = x;
    }

    void setY(int y) {
        posY = y;
    }

    // Méthodes pour définir la longueur et la largeur
    void setLength(int length) {
        lon = length;
    }

    void setWidth(int width) {
        lar = width;
    }

    // Méthode pour afficher les informations de l'objet
    void printInfo() const {
        cout << "Position (X, Y): (" << posX << ", " << posY << "), Longueur: " << lon << ", Largeur: " << lar << std::endl;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    void updatePosition(const sf::RenderWindow& window) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        shape.setPosition(static_cast<sf::Vector2f>(mousePosition));

    }
};
