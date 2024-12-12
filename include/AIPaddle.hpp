#ifndef AIPADDLE_HPP
#define AIPADDLE_HPP

#include "Paddle.hpp"
#include "Ball.hpp"

class AIPaddle : public Paddle {
private:
    const Ball& ball;

public:
    AIPaddle(float x, float y, float width, float height, float speed, const Ball& ball);

    void update(float deltaTime) override;
};

#endif
