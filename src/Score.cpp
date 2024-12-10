#include "Score.hpp"

Score::Score() : playerScore(0), aiScore(0) {
    font.loadFromFile("data/arial.ttf");
    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(24);
    playerScoreText.setPosition(200, 20);
    playerScoreText.setFillColor(sf::Color::White);

    aiScoreText.setFont(font);
    aiScoreText.setCharacterSize(24);
    aiScoreText.setPosition(600, 20);
    aiScoreText.setFillColor(sf::Color::White);
}

void Score::update(Ball& ball) {
    if (ball.getPosition().x < 0) {
        ++aiScore;
        ball.setPosition(400.0f, 300.0f);
        ball.setVelocity(-0.2f, -0.2f);
    } else if (ball.getPosition().x > 800) {
        ++playerScore;
        ball.setPosition(400.0f, 300.0f);
        ball.setVelocity(0.2f, 0.2f);
    }

    playerScoreText.setString(std::to_string(playerScore));
    aiScoreText.setString(std::to_string(aiScore));
}

void Score::render(sf::RenderWindow& window) {
    window.draw(playerScoreText);
    window.draw(aiScoreText);
}