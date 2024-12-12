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
    sf::Font font;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text playerLabel; // Nueva variable para la etiqueta del jugador
    sf::Text aiLabel;
    // Variables para el sonido
    sf::SoundBuffer collisionBuffer;
    sf::Sound collisionSound;
};

#endif