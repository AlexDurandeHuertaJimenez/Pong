#include "Paddle.hpp"

// Constructor de la clase Paddle
Paddle::Paddle(float x, float y, float width, float height, float speed)
    : speed(speed) {
    shape.setSize(sf::Vector2f(width, height));  // Establecer el tamaño del paddle
    shape.setPosition(x, y);  // Establecer la posición del paddle
    shape.setFillColor(sf::Color::White);  // Establecer el color del paddle
}

// Método para dibujar el paddle en la ventana
void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Método vacío para actualizar el estado del paddle (debe ser implementado por clases derivadas)
void Paddle::update(float deltaTime) {
}

// Método para establecer la textura del paddle
void Paddle::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

// Método para obtener los límites del paddle para la detección de colisiones
sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}