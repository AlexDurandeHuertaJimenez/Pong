#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Score {
public:
    Score();
    void update(const Ball& ball);  // Actualiza el puntaje basado en la posición de la pelota
    void render(sf::RenderWindow& window);  // Dibuja el puntaje
    void reset();  // Reinicia los puntajes
    void resetBall(Ball& ball);  // Resetea la posición de la bola al centro

private:
    int playerScore;
    int aiScore;
    sf::Font font;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
};

#endif
