#include "Ball.hpp"
#include "Paddle.hpp"
#include <iostream>

// Constructor que inicializa la pelota con su radio, posición y otros atributos
Ball::Ball(float radius, float x, float y) 
    : shape(radius + 5), velocity(-350.0f, -350.0f) {
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    
    // Cargar la textura de la pelota
    if (!texture.loadFromFile("assets/images/Ball.png")) {
        std::cerr << "Error loading ball texture" << std::endl;
    }
    shape.setTexture(&texture);

    // Cargar el archivo de sonido
    if (!buffer.loadFromFile("assets/sounds/bounce.ogg")) {
        // Manejar error al cargar el archivo de sonido
        std::cerr << "Error al cargar el archivo de sonido" << std::endl;
    } 
    sound.setBuffer(buffer);
}

// Método para actualizar la posición y manejo de colisiones de la pelota
void Ball::update(float deltaTime, const Paddle& playerPaddle, const Paddle& aiPaddle) {
    shape.move(velocity * deltaTime);

    // Obtener la posición y los límites de la pelota
    float ballTop = shape.getPosition().y;
    float ballBottom = shape.getPosition().y + shape.getRadius() * 2;

    // Rebotar en los bordes superior e inferior de la pantalla
    if (ballTop <= 0 || ballBottom >= 600) {
        if (sound.getStatus() != sf::Sound::Playing) {
            sound.play();  // Reproducir el sonido de rebote
        }
        rebound(false);
    }

    // Rebotar en los paddles
    if (shape.getGlobalBounds().intersects(playerPaddle.getBounds())) {
        velocity.x = std::abs(velocity.x); // Asegurar que la pelota rebote en la dirección correcta
    } else if (shape.getGlobalBounds().intersects(aiPaddle.getBounds())) {
        velocity.x = -std::abs(velocity.x); // Asegurar que la pelota rebote en la dirección correcta
    }
}

// Método para renderizar la pelota en la ventana
void Ball::render(sf::RenderWindow& window) {
    window.draw(shape);
}

// Establecer la posición de la pelota
void Ball::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

// Establecer la velocidad de la pelota
void Ball::setVelocity(float vx, float vy) {
    velocity = {vx, vy};
}

// Obtener la posición de la pelota
sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

// Implementación del método getVelocity para obtener la velocidad de la pelota
sf::Vector2f Ball::getVelocity() const {
    return velocity;
}

// Obtener los límites de la pelota para detección de colisiones
sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

// Método para hacer rebotar la pelota en una dirección específica
void Ball::rebound(bool horizontal) {
    if (horizontal)
        velocity.x = -velocity.x;
    else
        velocity.y = -velocity.y;
}