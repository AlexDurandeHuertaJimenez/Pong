#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong"), 
      ball(400.f, 300.f, 10.f, 200.f, 200.f), 
      playerPaddle(20.f, 250.f, 10.f, 100.f, 300.f),
      aiPaddle(770.f, 250.f, 10.f, 100.f, 300.f, ball) {}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        processEvents();
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
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

void Game::update(float deltaTime) {
    playerPaddle.update(deltaTime);
    aiPaddle.update(deltaTime);
    ball.update(deltaTime);
}

void Game::render() {
    window.clear();
    playerPaddle.draw(window);
    aiPaddle.draw(window);
    ball.draw(window);
    window.display();
}
