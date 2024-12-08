#include "Paddle.hpp"

Paddle::Paddle(float x, float y) {
    shape.setSize(sf::Vector2f(20.f, 100.f)); // Tamaño del paddle
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White); // Color del paddle
    speed = 1.0f; // Velocidad reducida para los paddles
}

void Paddle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::RectangleShape Paddle::getShape() const {
    return shape;
}

// PlayerPaddle
PlayerPaddle::PlayerPaddle(float x, float y) : Paddle(x, y) {}

void PlayerPaddle::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        moveDown();
    }
}

void PlayerPaddle::moveUp() {
    if (shape.getPosition().y > 0) {
        shape.move(0, -speed);  // Velocidad reducida
    }
}

void PlayerPaddle::moveDown() {
    if (shape.getPosition().y + shape.getSize().y < 600) {
        shape.move(0, speed);  // Velocidad reducida
    }
}

// AiPaddle
AiPaddle::AiPaddle(float x, float y) : Paddle(x, y) {}

void AiPaddle::update() {
    // Movimientos de la IA (solo por demostración)
    if (shape.getPosition().y + shape.getSize().y / 2 < 300) {
        shape.move(0, speed);
    }
    if (shape.getPosition().y + shape.getSize().y / 2 > 300) {
        shape.move(0, -speed);
    }
}
