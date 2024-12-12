#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.hpp"
#include "PlayerPaddle.hpp"
#include "AIPaddle.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    Ball ball;
    PlayerPaddle playerPaddle;
    AIPaddle aiPaddle;
    int playerScore;
    int aiScore;
    float timeSinceLastPoint; // Nueva variable para el temporizador
    sf::Font font;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Text countdownText; // Nueva variable para el texto de cuenta regresiva
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text playerLabel;
    sf::Text aiLabel;
    sf::Texture playerPaddleTexture;
    sf::Texture aiPaddleTexture;
    sf::SoundBuffer collisionBuffer;
    sf::Sound collisionSound;
};

#endif