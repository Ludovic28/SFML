#include "Collider.h"

bool Collider::checkCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2) {
    return rect1.intersects(rect2);
}

bool Collider::checkCollision(const sf::CircleShape& circle, const sf::FloatRect& rect) {
    return circle.getGlobalBounds().intersects(rect);
}

bool Collider::checkCollision(const sf::CircleShape& circle1, const sf::CircleShape& circle2) {
    return circle1.getGlobalBounds().intersects(circle2.getGlobalBounds());
}
