#ifndef PLAYERPADDLE_HPP
#define PLAYERPADDLE_HPP

#include <SFML/Graphics.hpp>

class PlayerPaddle {
public:
    PlayerPaddle(float x, float y);

    void move(float dy);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
};

#endif
