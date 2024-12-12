#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.hpp"
#include "PlayerPaddle.hpp"
#include "AIPaddle.hpp"

// Clase principal del juego que maneja la lógica y el renderizado
class Game {
public:
    // Constructor para inicializar los elementos del juego
    Game();
    // Método principal para ejecutar el bucle del juego
    void run();

private:
    // Método para procesar eventos de entrada del usuario
    void processEvents();
    // Método para actualizar el estado del juego
    void update(float deltaTime);
    // Método para renderizar los elementos del juego
    void render();

    sf::RenderWindow window;          // Ventana del juego
    Ball ball;                        // Objeto de la pelota
    PlayerPaddle playerPaddle;        // Objeto del paddle del jugador
    AIPaddle aiPaddle;                // Objeto del paddle controlado por IA
    int playerScore;                  // Puntuación del jugador
    int aiScore;                      // Puntuación del AI
    float timeSinceLastPoint;         // Tiempo desde el último punto anotado
    sf::Font font;                    // Fuente para el texto
    sf::Text playerScoreText;         // Texto para la puntuación del jugador
    sf::Text aiScoreText;             // Texto para la puntuación del AI
    sf::Text countdownText;           // Texto para la cuenta regresiva
    sf::Texture backgroundTexture;    // Textura para el fondo del juego
    sf::Sprite backgroundSprite;      // Sprite para el fondo del juego
    sf::Text playerLabel;             // Etiqueta de texto para el jugador
    sf::Text aiLabel;                 // Etiqueta de texto para la IA
    sf::Texture playerPaddleTexture;  // Textura para el paddle del jugador
    sf::Texture aiPaddleTexture;      // Textura para el paddle de la IA
    sf::SoundBuffer collisionBuffer;  // Buffer de sonido para colisiones
    sf::Sound collisionSound;         // Sonido de colisión
};

#endif