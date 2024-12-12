#ifndef PLAYERPADDLE_HPP
#define PLAYERPADDLE_HPP

#include "Paddle.hpp"

class PlayerPaddle : public Paddle {
public:
    PlayerPaddle(float x, float y, float width, float height, float speed);
    void update(float deltaTime) override;
};

#endif
