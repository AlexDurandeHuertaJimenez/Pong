#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.hpp"

// Clase que representa la pelota en el juego
class Ball {
public:
    // Constructor que inicializa la pelota con su radio y posición
    Ball(float radius, float x, float y);

    // Actualiza la posición de la pelota y maneja colisiones
    void update(float deltaTime, const Paddle& playerPaddle, const Paddle& aiPaddle);
    // Renderiza la pelota en la ventana
    void render(sf::RenderWindow& window);

    // Establece la posición de la pelota
    void setPosition(float x, float y);
    // Establece la velocidad de la pelota
    void setVelocity(float vx, float vy);
    // Obtiene la posición de la pelota
    sf::Vector2f getPosition() const;
    // Obtiene la velocidad de la pelota
    sf::Vector2f getVelocity() const;
    // Obtiene los límites de la pelota para detección de colisiones
    sf::FloatRect getBounds() const;
    // Rebota la pelota en una dirección específica (horizontal o vertical)
    void rebound(bool horizontal);

private:
    sf::CircleShape shape;      // Representación gráfica de la pelota
    sf::Vector2f velocity;      // Velocidad de la pelota
    sf::SoundBuffer buffer;     // Buffer de sonido para la pelota
    sf::Sound sound;            // Sonido de la pelota
    sf::Texture texture;        // Textura de la pelota
};

#endif