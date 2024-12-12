#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "PlayerPaddle.hpp"
#include "AIPaddle.hpp"

class Game {
private:
    sf::RenderWindow window;
    Ball ball;
    PlayerPaddle playerPaddle;  // Cambiado a PlayerPaddle
    AIPaddle aiPaddle;

public:
    Game();
    void run();
    void processEvents();
    void update(float deltaTime);
    void render();
};

#endif
