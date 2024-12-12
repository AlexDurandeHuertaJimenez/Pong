#ifndef PLAYERPADDLE_HPP
#define PLAYERPADDLE_HPP

#include "Paddle.hpp"

// Clase que representa el paddle controlado por el jugador
class PlayerPaddle : public Paddle {
public:
    // Constructor que inicializa el paddle del jugador con su posición, tamaño y velocidad
    PlayerPaddle(float x, float y, float width, float height, float speed);
    // Actualiza la posición del paddle del jugador según las entradas del teclado
    void update(float deltaTime) override;
};

#endif