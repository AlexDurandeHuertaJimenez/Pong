#include "Game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Pong Game"),
               score(), playerPaddle(10.0f, 100.0f, 10.0f, 300.0f), 
               aiPaddle(10.0f, 100.0f, 780.0f, 300.0f), ball(10.0f) {}

void Game::run() {
    while (window.isOpen()) {
        update();
        render();
    }
}

void Game::update() {
    sf::Time deltaTime = clock.restart();
    
    // Actualiza la pelota y las palas
    ball.update(deltaTime.asSeconds());
    playerPaddle.update();
    aiPaddle.update(ball);
    
    // Verifica si la pelota sale de los límites izquierdo o derecho
    if (ball.getPosition().x < 0 || ball.getPosition().x > 800) {
        score.update(ball);  // Actualiza el marcador
        ball.reset();  // Resetea la pelota al centro
    }

    checkCollisions();
}

void Game::render() {
    window.clear();
    window.draw(ball);
    ball.render(window);
    playerPaddle.render(window);
    aiPaddle.render(window);
    score.render(window); // Asegúrate de agregar el renderizado del score
    window.display();
}

void Game::checkCollisions() {
    // Colisión con el paddle del jugador
    if (ball.getGlobalBounds().intersects(playerPaddle.getGlobalBounds())) {
        ball.setVelocity(-ball.getVelocity().x, ball.getVelocity().y);
    }

    // Colisión con el paddle de la IA
    if (ball.getGlobalBounds().intersects(aiPaddle.getGlobalBounds())) {
        ball.setVelocity(-ball.getVelocity().x, ball.getVelocity().y);
    }

    // Colisión con los bordes superior e inferior
    if (ball.getPosition().y <= 0 || ball.getPosition().y >= 600) {
        ball.setVelocity(ball.getVelocity().x, -ball.getVelocity().y);
    }

    // Colisión con los bordes izquierdo y derecho
    if (ball.getPosition().x <= 0 || ball.getPosition().x >= 800) {
        ball.setVelocity(-ball.getVelocity().x, ball.getVelocity().y);
    }
}