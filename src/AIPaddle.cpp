#include "AiPaddle.hpp"
#include <SFML/Window.hpp>

AiPaddle::AiPaddle(float width, float height, float x, float y) 
    : sf::RectangleShape(sf::Vector2f(width, height)), speed(0.2f) {
    this->setPosition(x, y);
}

void AiPaddle::update(const Ball& ball) {
    sf::Vector2f ballPosition = ball.getPosition();
    // La IA sigue la pelota en el eje Y, puedes agregar lógica para que se mueva hacia la pelota
    if (ballPosition.y < getPosition().y) {
        move(0, -speed * 2.0f);  // Mueve hacia arriba
    } else if (ballPosition.y > getPosition().y) {
        move(0, speed * 2.0f);  // Mueve hacia abajo
    }

    // Limita el movimiento de la IA Paddle para que no se salga de la ventana
    if (getPosition().y < 0) {
        setPosition(getPosition().x, 0);  // Limita al borde superior
    } else if (getPosition().y + getGlobalBounds().height > 600) {
        setPosition(getPosition().x, 600 - getGlobalBounds().height);  // Limita al borde inferior
    }
}

sf::FloatRect AiPaddle::getBounds() const {
    return getGlobalBounds();
}

void AiPaddle::render(sf::RenderWindow& window) {
    window.draw(*this);
}
