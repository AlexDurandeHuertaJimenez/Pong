#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float x, float y);                          // Constructor
    void move(float offsetY);                           // Mover la paleta
    const sf::RectangleShape& getShape() const;         // Obtener la forma de la paleta

protected:
    sf::RectangleShape shape;                           // Forma de la paleta
};

#endif
