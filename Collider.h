#pragma once
#include <SFML/Graphics.hpp>

class Collider {
public:
    static bool checkCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
    static bool checkCollision(const sf::CircleShape& circle, const sf::FloatRect& rect);
    static bool checkCollision(const sf::CircleShape& circle1, const sf::CircleShape& circle2);
    // Ajoutez d'autres m�thodes pour d'autres types de collisions

private:
    // Ajoutez des m�thodes priv�es si n�cessaire
};

