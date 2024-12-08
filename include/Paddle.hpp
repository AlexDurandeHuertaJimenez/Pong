#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float x, float y);
    virtual void update() = 0;
    void render(sf::RenderWindow& window);
    sf::RectangleShape getShape() const;

protected:
    sf::RectangleShape shape;
    float speed;
};

class PlayerPaddle : public Paddle {
public:
    PlayerPaddle(float x, float y);
    void update() override;
    void moveUp();
    void moveDown();
};

class AiPaddle : public Paddle {
public:
    AiPaddle(float x, float y);
    void update() override;
};

#endif
