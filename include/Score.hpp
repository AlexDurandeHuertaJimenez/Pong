#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"
class Score {
public:
    Score();
    void update(const Ball& ball);  // Actualizar el puntaje
    void render(sf::RenderWindow& window);
    void reset();  // Reiniciar el puntaje

private:
    int playerScore;
    int aiScore;
    sf::Font font;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
};

#endif
