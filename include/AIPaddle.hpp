#ifndef AIPADDLE_HPP
#define AIPADDLE_HPP

#include "Paddle.hpp"
#include "Ball.hpp"

// Clase que representa el paddle controlado por la IA
class AIPaddle : public Paddle {
private:
    const Ball &ball; // Referencia a la pelota para seguir su movimiento

public:
    // Constructor que inicializa el paddle de la IA con su posición, tamaño, velocidad y referencia a la pelota
    AIPaddle(float x, float y, float width, float height, float speed, const Ball &ball);
    // Actualiza la posición del paddle de la IA para seguir la pelota
    void update(float deltaTime) override;
};

#endif