#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Score.hpp"

class Game {
public:
    Game();
    void run();
    void update();

private:
    sf::RenderWindow window;
    PlayerPaddle playerPaddle;
    AiPaddle aiPaddle;
    Ball ball;
    Score score;
};

#endif
