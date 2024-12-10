#include "Ball.hpp"
#include <cstdlib>
#include <ctime>

Ball::Ball(float radius) : sf::CircleShape(radius), velocity(0.2f, 0.2f) {
    this->setFillColor(sf::Color::Red);
    this->setPosition(400, 300);  // Posición inicial al centro
    srand(static_cast<unsigned int>(time(0)));  // Inicializar semilla aleatoria
}

void Ball::update(float deltaTime) {
    move(velocity * deltaTime * 500.0f);
    if (getPosition().y <= 0) {
        setPosition(getPosition().x, 0);  // Asegura que no se quede pegada al borde superior
        velocity.y = -velocity.y;  // Rebote hacia abajo
    }
    else if (getPosition().y + getGlobalBounds().height >= 600) {
        setPosition(getPosition().x, 600 - getGlobalBounds().height);  // Asegura que no se quede pegada al borde inferior
        velocity.y = -velocity.y;  // Rebote hacia arriba
    }

    // Rebote con los bordes izquierdo y derecho
    if (getPosition().x <= 0) {
        setPosition(0, getPosition().y);  // Asegura que no se quede pegada al borde izquierdo
        velocity.x = -velocity.x;  // Rebote hacia la derecha
    }
    else if (getPosition().x + getGlobalBounds().width >= 800) {
        setPosition(800 - getGlobalBounds().width, getPosition().y);  // Asegura que no se quede pegada al borde derecho
        velocity.x = -velocity.x;  // Rebote hacia la izquierda
    }
}

void Ball::setVelocity(float x, float y) {
    velocity = sf::Vector2f(x, y);  // Establece la velocidad
}

void Ball::reset() {
    // Posición en el centro de la ventana
    this->setPosition(400, 300);

    // Velocidad aleatoria
    float directionX = (rand() % 2 == 0) ? 0.2f : -0.2f;  // Dirección aleatoria horizontal
    float directionY = (rand() % 2 == 0) ? 0.2f : -0.2f;  // Dirección aleatoria vertical
    this->velocity = sf::Vector2f(directionX, directionY);
}

void Ball::render(sf::RenderWindow& window) {
    window.draw(*this);
}

void Ball::rebound(bool vertical) {
    if (vertical) {
        velocity.y = -velocity.y;
    } else {
        velocity.x = -velocity.x;
    }
}

sf::FloatRect Ball::getBounds() const {
    return getGlobalBounds();
}

sf::Vector2f Ball::getPosition() const {
    return sf::CircleShape::getPosition();  // Llamada a la función de la clase base
}

void Ball::setPosition(float x, float y) {
    sf::CircleShape::setPosition(x, y);
}
