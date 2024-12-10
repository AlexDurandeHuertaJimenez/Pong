#include "AiPaddle.hpp"

AiPaddle::AiPaddle(float x, float y) : Paddle(x, y) {
    shape.setSize({10.0f, 100.0f});
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void AiPaddle::moveTowards(float targetY) {
    float paddleY = shape.getPosition().y + shape.getSize().y / 2;
    if (paddleY < targetY)
        shape.move(0.0f, 0.2f);
    else if (paddleY > targetY)
        shape.move(0.0f, -0.2f);
}

void AiPaddle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f AiPaddle::getPosition() const {
    return shape.getPosition();
}

sf::FloatRect AiPaddle::getBounds() const {
    return shape.getGlobalBounds();
}

void AiPaddle::update(const Ball& ball) {
    if (ball.getPosition().y < shape.getPosition().y) {
        move(-0.2f);  // Mueve hacia arriba
    } else if (ball.getPosition().y > shape.getPosition().y + shape.getSize().y) {
        move(0.2f);   // Mueve hacia abajo
    }
}