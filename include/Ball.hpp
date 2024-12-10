#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
public:
    Ball(float radius = 10.0f);
    void update(float deltaTime);
    void reset();
    void render(sf::RenderWindow& window);
    void rebound(bool vertical);
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    void setVelocity(float x, float y);  // Declaración sin definición en línea
    sf::Vector2f getVelocity() const { return velocity; }

private:
    sf::Vector2f velocity;
};

#endif // BALL_HPP