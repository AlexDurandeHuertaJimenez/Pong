#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Score {
public:
    Score();
    void update(Ball& ball);
    void render(sf::RenderWindow& window);

private:
    int playerScore;
    int aiScore;
    sf::Font font;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
};

#endif
