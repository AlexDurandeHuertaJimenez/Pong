#include "Score.hpp"
#include "Ball.hpp"
Score::Score() {
    playerScore = 0;
    aiScore = 0;
    
    if (!font.loadFromFile("arial.ttf")) {
        // Manejo de error
    }

    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(24);
    playerScoreText.setFillColor(sf::Color::White);
    playerScoreText.setPosition(350, 10);

    aiScoreText.setFont(font);
    aiScoreText.setCharacterSize(24);
    aiScoreText.setFillColor(sf::Color::White);
    aiScoreText.setPosition(450, 10);
}

void Score::update(const Ball& ball) {
    // Actualizar el puntaje cuando la pelota sale
    if (ball.getPosition().x < 0) {
        aiScore++;
        resetBall(ball);
    }
    if (ball.getPosition().x > 800) {
        playerScore++;
        resetBall(ball);
    }

    playerScoreText.setString(std::to_string(playerScore));
    aiScoreText.setString(std::to_string(aiScore));
}

void Score::resetBall(const Ball& ball) {
    ball.respawn();  // Hacer respawn de la pelota
}

void Score::render(sf::RenderWindow& window) {
    window.draw(playerScoreText);
    window.draw(aiScoreText);
}

void Score::reset() {
    playerScore = 0;
    aiScore = 0;
}
