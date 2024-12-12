#include "PlayerPaddle.hpp"
#include <SFML/Window/Keyboard.hpp>

PlayerPaddle::PlayerPaddle(float x, float y, float width, float height, float speed)
    : Paddle(x, y, width, height, speed) {
    shape.setSize(sf::Vector2f(width * 3, height));
    if (shape.getTexture()) {
        float scaleX = (width * 3) / shape.getTexture()->getSize().x;
        float scaleY = height / shape.getTexture()->getSize().y;
        shape.setScale(scaleX, scaleY);
    }
    }

void PlayerPaddle::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y > 0) {
        shape.move(0, -speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y + shape.getSize().y < 600) {
        shape.move(0, speed * deltaTime);
    }
}