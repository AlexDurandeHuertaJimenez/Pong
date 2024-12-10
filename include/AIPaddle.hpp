#ifndef AIPADDLE_HPP
#define AIPADDLE_HPP

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class AiPaddle : public sf::RectangleShape {
public:
    AiPaddle(float width, float height, float x, float y);
    void update(const Ball& ball);
    
    // Métodos añadidos
    sf::FloatRect getBounds() const;
    void render(sf::RenderWindow& window);
    
private:
    float speed;
};

#endif
