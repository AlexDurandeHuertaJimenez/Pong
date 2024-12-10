#include "Ball.hpp"

Ball::Ball(float radius, float x, float y) 
    : shape(radius), velocity(-0.2f, -0.2f) {
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Ball::update() {
    shape.move(velocity);
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Ball::setVelocity(float vx, float vy) {
    velocity = {vx, vy};
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

void Ball::rebound(bool horizontal) {
    if (horizontal)
        velocity.x = -velocity.x;
    else
        velocity.y = -velocity.y;
}
