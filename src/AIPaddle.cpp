#include "AIPaddle.hpp"

// Constructor de la clase AIPaddle
AIPaddle::AIPaddle(float x, float y, float width, float height, float speed, const Ball& ball)
    : Paddle(x, y, width, height, speed), ball(ball) {
        // Ajustar el tamaño de la paleta
        shape.setSize(sf::Vector2f(width * 3, height));
        // Ajustar la escala de la textura si está presente
        if (shape.getTexture()) {
        float scaleX = (width * 3) / shape.getTexture()->getSize().x;
        float scaleY = height / shape.getTexture()->getSize().y;
        shape.setScale(scaleX, scaleY);
    }
}

// Método para actualizar la posición de la paleta de la IA
void AIPaddle::update(float deltaTime) {
    // Obtener la posición Y de la pelota y predecir su posición futura
    float ballY = ball.getBounds().top + ball.getBounds().height / 2;
    float ballFutureY = ballY + ball.getVelocity().y * deltaTime * 10; // Predicción simple

    float paddleY = shape.getPosition().y + shape.getSize().y / 2;

    // Mover la paleta en función de la posición futura de la pelota
    if (paddleY < ballFutureY && shape.getPosition().y + shape.getSize().y < 600) {
        shape.move(0, speed * deltaTime);
    } else if (paddleY > ballFutureY && shape.getPosition().y > 0) {
        shape.move(0, -speed * deltaTime);
    }
}