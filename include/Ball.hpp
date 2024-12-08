#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, float x, float y);
    void update();
    void render(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    void respawn();  // Método para hacer respawn de la pelota

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif
