#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, sf::Color color) : GameObject(x, y, width, height){
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);
    isDestroyed_ = false;
}

void Brick::draw(sf::RenderWindow& window) {
    if (!isDestroyed_) {
        window.draw(shape);
    }
}

bool Brick::intersects(Ball& otherObject, float bounceAngle) {
    if (Collider::checkCollision(otherObject.getGlobalBounds(), shape.getGlobalBounds())) {

        if (isDestroyed_) {
            return false; // Pas de collision avec une brique détruite
        }

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

        destroy();
        
        return true; // Collision détectée
    }

    return false; // Pas de collision
}

sf::FloatRect Brick::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

std::vector<Brick> Brick::createBricks(sf::RenderWindow& window, int rows, int cols, float gap) {
    std::vector<Brick> bricks;  // Créer un vecteur local pour stocker les briques

    // Calculer la largeur disponible pour les briques
    float availableWidth = window.getSize().x - (cols + 1) * gap;

    // Calculer la largeur d'une brique
    float brickWidth = availableWidth / cols;

    // Définir la hauteur d'une brique (vous pouvez ajuster cela selon vos besoins)
    float brickHeight = 100 / rows;

    // Créer les briques en fonction du nombre de lignes et de colonnes
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            float x = gap + col * (brickWidth + gap);
            float y = gap + row * (brickHeight + gap);

            // Ajouter la brique au vecteur local
            bricks.push_back(Brick(x, y, brickWidth, brickHeight, sf::Color::Green));
        }
    }

    return bricks;  // Retourner le vecteur local de briques
}

bool Brick::isDestroyed() const {
    return isDestroyed_;
}

void Brick::destroy() {
    isDestroyed_ = true;
}