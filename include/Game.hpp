#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "PlayerPaddle.hpp"
#include "AiPaddle.hpp"
#include "Score.hpp"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    Ball ball;
    PlayerPaddle playerPaddle;
    AiPaddle aiPaddle;
    Score score;

    void processEvents();
    void update();
    void render();
};

#endif
