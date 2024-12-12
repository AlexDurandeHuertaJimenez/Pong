#include "PlayerPaddle.hpp"
#include <SFML/Window/Keyboard.hpp>

// Constructor de la clase PlayerPaddle
PlayerPaddle::PlayerPaddle(float x, float y, float width, float height, float speed)
    : Paddle(x, y, width, height, speed) {
    // Ajustar el tamaño de la paleta del jugador
    shape.setSize(sf::Vector2f(width * 3, height));
    // Ajustar la escala de la textura si está presente
    if (shape.getTexture()) {
        float scaleX = (width * 3) / shape.getTexture()->getSize().x;
        float scaleY = height / shape.getTexture()->getSize().y;
        shape.setScale(scaleX, scaleY);
    }
}

// Método para actualizar la posición del paddle del jugador según las entradas del teclado
void PlayerPaddle::update(float deltaTime) {
    // Mover el paddle hacia arriba si se presiona la tecla 'W' y el paddle no está en el borde superior
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y > 0) {
        shape.move(0, -speed * deltaTime);
    }
    // Mover el paddle hacia abajo si se presiona la tecla 'S' y el paddle no está en el borde inferior
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y + shape.getSize().y < 600) {
        shape.move(0, speed * deltaTime);
    }
}