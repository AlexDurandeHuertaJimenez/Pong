#include "Game.hpp"

Game::Game() 
    : window(sf::VideoMode(800, 600), "Pong"),
      ball(10.0f, 400.0f, 300.0f),
      playerPaddle(50.0f, 250.0f),
      aiPaddle(750.0f, 250.0f) {}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    ball.update();

    // AI Paddle movement
    aiPaddle.moveTowards(ball.getPosition().y);

    // Collision detection
    if (ball.getBounds().intersects(playerPaddle.getBounds())) {
        ball.rebound(true);
    } else if (ball.getBounds().intersects(aiPaddle.getBounds())) {
        ball.rebound(true);
    }

    score.update(ball);
}

void Game::render() {
    window.clear();
    ball.render(window);
    playerPaddle.render(window);
    aiPaddle.render(window);
    score.render(window);
    window.display();
}
