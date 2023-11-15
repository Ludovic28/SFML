#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(int x, int y, int length, int width)
    : posX(x), posY(y), lon(length), lar(width)
{
    shape.setSize(sf::Vector2f(lon, lar));
    shape.setPosition(sf::Vector2f(posX, posY));
    shape.setFillColor(sf::Color::Blue);
}

int GameObject::getX() const {
    return posX;
}

int GameObject::getY() const {
    return posY;
}

int GameObject::getLength() const {
    return lon;
}

int GameObject::getWidth() const {
    return lar;
}

void GameObject::setX(int x) {
    posX = x;
}

void GameObject::setY(int y) {
    posY = y;
}

void GameObject::setLength(int length) {
    lon = length;
}

void GameObject::setWidth(int width) {
    lar = width;
}

void GameObject::printInfo() const {
    // Utilisez std::cout au lieu de cout
    cout << "Position (X, Y): (" << posX << ", " << posY << "), Longueur: " << lon << ", Largeur: " << lar << std::endl;
}

void GameObject::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void GameObject::updatePosition(const sf::RenderWindow& window) {
    // R�cup�rer la position actuelle de l'objet
    sf::Vector2f currentPosition = shape.getPosition();

    // Mettre � jour la position de l'objet (d�placement vers la droite, par exemple)
    float movementSpeed = 2.0f;
    float newX = currentPosition.x + movementSpeed;
    float newY = currentPosition.y;

    // V�rifier que la nouvelle position reste � l'int�rieur de la fen�tre
    if (newX < 0) {
        newX = 0;
    }
    if (newX + lon > window.getSize().x) {
        newX = window.getSize().x - lon;
    }
    if (newY < 0) {
        newY = 0;
    }
    if (newY + lar > window.getSize().y) {
        newY = window.getSize().y - lar;
    }

    // D�finir la nouvelle position de l'objet
    shape.setPosition(newX, newY);
}

// Ajoutez les fonctions pour obtenir et d�finir la position de l'objet
void GameObject::setPosition(int x, int y) {
    posX = x;
    posY = y;
    shape.setPosition(sf::Vector2f(posX, posY));
}

bool GameObject::intersects(const GameObject& other) const {
    // Obtenez la bo�te englobante de cet objet
    sf::FloatRect thisBounds = shape.getGlobalBounds();

    // Obtenez la bo�te englobante de l'autre objet
    sf::FloatRect otherBounds = other.shape.getGlobalBounds();

    // V�rifiez l'intersection des deux bo�tes englobantes
    return thisBounds.intersects(otherBounds);
}

sf::FloatRect GameObject::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

