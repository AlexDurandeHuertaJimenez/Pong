#include "AiPaddle.hpp"
#include "Ball.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Constructor de la clase AiPaddle
AiPaddle::AiPaddle(float width, float height, float x, float y)
    : sf::RectangleShape(sf::Vector2f(width, height)), speed(0.2f)
{
    this->setPosition(x, y);
}

// Actualización de la posición de la paleta basada en la posición de la pelota
void AiPaddle::update(const Ball &ball)
{
    sf::Vector2f ballPosition = ball.getPosition();

    // La IA sigue la pelota en el eje Y
    if (ballPosition.y < getPosition().y)
    {
        move(0, -speed * 2.0f); // Mueve hacia arriba
    }
    else if (ballPosition.y > getPosition().y)
    {
        move(0, speed * 2.0f); // Mueve hacia abajo
    }

    // Limita el movimiento de la IA Paddle para que no se salga de la ventana
    float windowHeight = 600; // Altura de la ventana (puede parametrizarse)
    float paddleHeight = getGlobalBounds().height;

    if (getPosition().y < 0)
    {
        setPosition(getPosition().x, 0); // Limita al borde superior
    }
    else if (getPosition().y + paddleHeight > windowHeight)
    {
        setPosition(getPosition().x, windowHeight - paddleHeight); // Limita al borde inferior
    }
}

// Devuelve los límites globales de la paleta para detección de colisiones
sf::FloatRect AiPaddle::getBounds() const
{
    return getGlobalBounds();
}

// Renderiza la paleta en la ventana
void AiPaddle::render(sf::RenderWindow &window)
{
    window.draw(*this);
}

// Archivo Ball.cpp
#include "Ball.hpp"

Ball::Ball(float radius) : sf::CircleShape(radius), velocity(0.3f, 0.3f)
{
    setPosition(400, 300);
}

void Ball::update(float deltaTime)
{
    move(velocity);

    // Rebota en los bordes superior e inferior
    float windowHeight = 600; // Altura de la ventana (puede parametrizarse)

    if (getPosition().y < 0 || getPosition().y + getGlobalBounds().height > windowHeight)
    {
        velocity.y = -velocity.y;
    }
}

sf::Vector2f Ball::getPosition() const
{
    return sf::CircleShape::getPosition();
}