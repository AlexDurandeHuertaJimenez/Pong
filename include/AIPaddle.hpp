#ifndef AI_PADDLE_HPP
#define AI_PADDLE_HPP

#include "Paddle.hpp"
#include "Ball.hpp"

class AiPaddle : public Paddle {
public:
    AiPaddle(float x, float y);
    void update(const Ball& ball);  // Actualiza la posición de la IA según la pelota
};

#endif