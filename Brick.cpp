#include "Brick.h"

Brick::Brick(float x, float y, sf::Color color) {
    shape.setSize(sf::Vector2f(60, 20));
    shape.setPosition(x, y);
    shape.setFillColor(color);
    isDestroyed = false;
}

void Brick::draw(sf::RenderWindow& window) {
    if (!isDestroyed) {
        window.draw(shape);
    }
}

bool Brick::intersects(Ball& otherObject, float bounceAngle) const {
    if (Collider::checkCollision(otherObject.getGlobalBounds(), shape.getGlobalBounds())) {
        sf::Vector2f ballVelocity = otherObject.getVelocity();
        sf::Vector2f ballPosition = otherObject.getPosition();

        float brickRight = shape.getPosition().x + shape.getSize().x;
        float brickLeft = shape.getPosition().x;
        float brickTop = shape.getPosition().y;
        float brickBottom = shape.getPosition().y + shape.getSize().y;

        float ballRight = ballPosition.x + otherObject.getRadius();
        float ballLeft = ballPosition.x - otherObject.getRadius();
        float ballTop = ballPosition.y - otherObject.getRadius();
        float ballBottom = ballPosition.y + otherObject.getRadius();

        // Calcule l'angle de rebond en radians
        float angle = bounceAngle * 3.14159265359 / 180.0;

        // Inverser la composante x du vecteur de déplacement en fonction du côté de la collision
        if ((ballVelocity.x < 0 && ballRight > brickLeft && ballLeft < brickRight) ||
            (ballVelocity.x > 0 && ballLeft < brickRight && ballRight > brickLeft)) {


            float newVelocityX = std::cos(angle) * ballVelocity.x - std::sin(angle) * ballVelocity.y;

            ballVelocity.x = newVelocityX;

            // Ajuster la position de la balle pour éviter la pénétration
            if (ballVelocity.x > 0) {
                // Si la balle se déplace vers la droite, ajustez sa position à la gauche de la brique
                ballPosition.x = brickLeft - otherObject.getRadius();
            }
            else {
                // Sinon, ajustez la position à la droite de la brique
                ballPosition.x = brickRight + otherObject.getRadius();
            }
        }

        // Inverser la composante y du vecteur de déplacement en fonction du côté de la collision
        if ((ballVelocity.y < 0 && ballBottom > brickTop && ballTop < brickBottom) ||
            (ballVelocity.y > 0 && ballTop < brickBottom && ballBottom > brickTop)) {
            
            // Calcule les nouvelles composantes de la vélocité en fonction de l'angle
            float newVelocityY = std::sin(angle) * ballVelocity.x + std::cos(angle) * ballVelocity.y;
            // Applique les nouvelles composantes de la vélocité
            
            ballVelocity.y = newVelocityY;

            // Ajuster la position de la balle pour éviter la pénétration
            if (ballVelocity.y > 0) {
                // Si la balle se déplace vers le bas, ajustez sa position au-dessus de la brique
                ballPosition.y = brickTop - otherObject.getRadius();
            }
            else {
                // Sinon, ajustez la position en dessous de la brique
                ballPosition.y = brickBottom + otherObject.getRadius();
            }
        }

        // Appliquer la nouvelle direction à la balle
        otherObject.setVelocity(ballVelocity);
        otherObject.setPosition(ballPosition.x, ballPosition.y);

        return true; // Collision détectée
    }

    return false; // Pas de collision
}




sf::FloatRect Brick::getGlobalBounds() const {
    return shape.getGlobalBounds();
}