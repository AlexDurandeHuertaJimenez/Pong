#include "Score.hpp"
#include <iostream>

Score::Score() : playerScore(0), aiScore(0) {
    if (!font.loadFromFile("assets/fonts/Fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    playerScoreText.setFont(font);
    aiScoreText.setFont(font);

    playerScoreText.setCharacterSize(30);
    aiScoreText.setCharacterSize(30);

    playerScoreText.setFillColor(sf::Color::White);
    aiScoreText.setFillColor(sf::Color::White);
}

void Score::update(const Ball& ball) {
    // Si la bola pasa la posición X de la pantalla (fuera del campo de juego), incrementa el marcador
    if (ball.getPosition().x < 0) {
        aiScore++;
        resetBall(const_cast<Ball&>(ball));  // Restablece la bola
    }
    if (ball.getPosition().x > 800) {  // Asumiendo que el ancho de la ventana es 800px
        playerScore++;
        resetBall(const_cast<Ball&>(ball));  // Restablece la bola
    }

    // Actualiza los textos con el nuevo puntaje
    playerScoreText.setString("Player: " + std::to_string(playerScore));
    aiScoreText.setString("AI: " + std::to_string(aiScore));
}

void Score::render(sf::RenderWindow& window) {
    window.draw(playerScoreText);
    window.draw(aiScoreText);
}

void Score::reset() {
    playerScore = 0;
    aiScore = 0;
}

void Score::resetBall(Ball& ball) {
    // Resetea la posición y velocidad de la bola
    ball.setPosition(400.0f, 300.0f);  // Centro de la pantalla
    ball.setVelocity(-0.1f, -0.1f);  // Ajusta la velocidad de la bola
}
