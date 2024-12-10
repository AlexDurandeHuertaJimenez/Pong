#include "PlayerPaddle.hpp"
#include <SFML/Window.hpp>

PlayerPaddle::PlayerPaddle(float width, float height, float x, float y)
    : sf::RectangleShape(sf::Vector2f(width, height)), speed(0.2f) {
    setPosition(x, y);
}

void PlayerPaddle::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0, speed);
    }

    // Limita la pala del jugador para que no se salga de la ventana
    if (getPosition().y < 0) {
        setPosition(getPosition().x, 0);  // Limita al borde superior
    } else if (getPosition().y + getGlobalBounds().height > 600) {
        setPosition(getPosition().x, 600 - getGlobalBounds().height);  // Limita al borde inferior
    }
}

sf::FloatRect PlayerPaddle::getBounds() const {
    return getGlobalBounds();
}

void PlayerPaddle::render(sf::RenderWindow& window) {
    window.draw(*this);
}
