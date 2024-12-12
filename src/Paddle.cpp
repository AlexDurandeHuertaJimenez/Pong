#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height, float speed)
    : speed(speed) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Paddle::update(float deltaTime) {
}

void Paddle::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}
