#include "Ball.hpp"

Ball::Ball(float radius, float x, float y) {
    shape.setRadius(radius);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    velocity = sf::Vector2f(-0.05f, 0.05f); // Velocidad inicial de la pelota
}

void Ball::update() {
    shape.move(velocity);

    // Colisiones con los bordes de la pantalla
    if (shape.getPosition().y <= 0 || shape.getPosition().y + shape.getRadius() * 2 >= 600) {
        velocity.y = -velocity.y;  // Rebote vertical
    }
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

void Ball::respawn() {
    shape.setPosition(400, 300);  // Centrar la pelota
    velocity = sf::Vector2f(-0.05f, 0.05f);  // Reiniciar la dirección
}
