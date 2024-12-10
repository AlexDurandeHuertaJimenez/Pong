#include "Paddle.hpp"

Paddle::Paddle(float x, float y) {
    shape.setSize(sf::Vector2f(10.0f, 100.0f));   // Tamaño de la paleta
    shape.setPosition(x, y);                       // Posición inicial
    shape.setFillColor(sf::Color::White);          // Color blanco
}

void Paddle::move(float offsetY) {
    shape.move(0.0f, offsetY);                    // Mueve solo en el eje Y
}

const sf::RectangleShape& Paddle::getShape() const {
    return shape;                                 // Devuelve la forma de la paleta
}
