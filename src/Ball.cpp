#include "Ball.hpp"
#include "Paddle.hpp"
#include <iostream>

Ball::Ball(float radius, float x, float y) 
    : shape(radius), velocity(-350.0f, -350.0f) {
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);

    // Cargar el archivo de sonido
    if (!buffer.loadFromFile("assets/sounds/bounce.ogg")) {
        // Manejar error
        std::cerr << "Error al cargar el archivo de sonido" << std::endl;
        } 
    sound.setBuffer(buffer);
}

void Ball::update(float deltaTime, const Paddle& playerPaddle, const Paddle& aiPaddle) {
    shape.move(velocity * deltaTime);

    // Obtener la posición y los límites de la pelota
    float ballTop = shape.getPosition().y;
    float ballBottom = shape.getPosition().y + shape.getRadius() * 2;

    // Rebotar en los bordes superior e inferior de la pantalla
    if (ballTop <= 0 || ballBottom >= 600) {
        if (sound.getStatus() != sf::Sound::Playing) {
            sound.play();  // Reproducir el sonido
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

sf::Vector2f Ball::getVelocity() const { // Implementación del método getVelocity
    return velocity;
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