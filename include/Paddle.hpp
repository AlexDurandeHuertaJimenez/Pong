#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
protected:
    sf::RectangleShape shape;
    float speed;

public:
    Paddle(float x, float y, float width, float height, float speed);

    virtual void update(float deltaTime) = 0;
    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;
};

#endif
