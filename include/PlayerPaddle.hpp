#ifndef PLAYERPADDLE_HPP
#define PLAYERPADDLE_HPP

#include <SFML/Graphics.hpp>

class PlayerPaddle : public sf::RectangleShape {
public:
    PlayerPaddle(float width, float height, float x, float y);
    void update();
    
    // Métodos añadidos
    sf::FloatRect getBounds() const;
    void render(sf::RenderWindow& window);
    
private:
    float speed;
};

#endif
