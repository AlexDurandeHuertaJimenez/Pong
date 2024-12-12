#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, float x, float y);

    void update();
    void render(sf::RenderWindow& window);

    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);
    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;
    void rebound(bool horizontal);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif