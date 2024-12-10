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
    void update();
    void render();
    void checkCollisions();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    Ball ball;
    Score score;
    PlayerPaddle playerPaddle;
    AiPaddle aiPaddle;
};

#endif // GAME_HPP
