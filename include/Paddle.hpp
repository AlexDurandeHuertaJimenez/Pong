#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

// Clase base abstracta que representa un paddle en el juego
class Paddle {
protected:
    sf::RectangleShape shape; // Representación gráfica del paddle
    float speed;              // Velocidad del paddle

public:
    // Constructor que inicializa el paddle con su posición, tamaño y velocidad
    Paddle(float x, float y, float width, float height, float speed);
    // Método virtual puro que debe ser implementado por las clases derivadas para actualizar el paddle
    virtual void update(float deltaTime) = 0;
    // Renderiza el paddle en la ventana
    void draw(sf::RenderWindow& window);
    // Establece la textura del paddle
    void setTexture(const sf::Texture& texture);
    // Obtiene los límites del paddle para detección de colisiones
    sf::FloatRect getBounds() const;
};

#endif