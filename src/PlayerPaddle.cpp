#include "PlayerPaddle.hpp"

PlayerPaddle::PlayerPaddle(float x, float y) : Paddle(x, y) {
    shape.setSize({10.0f, 100.0f});
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void PlayerPaddle::move(float dy) {
    shape.move(0.0f, dy);
}

void PlayerPaddle::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void PlayerPaddle::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(-0.2f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0.2f);
    }
}

sf::Vector2f PlayerPaddle::getPosition() const {
    return shape.getPosition();
}

sf::FloatRect PlayerPaddle::getBounds() const {
    return shape.getGlobalBounds();
}
