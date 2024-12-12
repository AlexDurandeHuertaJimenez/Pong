#include "AIPaddle.hpp"

AIPaddle::AIPaddle(float x, float y, float width, float height, float speed, const Ball& ball)
    : Paddle(x, y, width, height, speed), ball(ball) {}

void AIPaddle::update(float deltaTime) {
    // Obtener la posición Y de la pelota
    float ballY = ball.getBounds().top + ball.getBounds().height / 2;
    float paddleY = shape.getPosition().y + shape.getSize().y / 2;

    // Mover la paleta en función de la posición de la pelota
    if (paddleY < ballY && shape.getPosition().y + shape.getSize().y < 600) {
        shape.move(0, speed * deltaTime);
    } else if (paddleY > ballY && shape.getPosition().y > 0) {
        shape.move(0, -speed * deltaTime);
    }
}
