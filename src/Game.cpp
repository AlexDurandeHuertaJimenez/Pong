#include "Game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Pong Game"), playerPaddle(50, 250), aiPaddle(730, 250), ball(10, 400, 300) {}

void Game::run() {
    while (window.isOpen()) {
        update();
    }
}

void Game::update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    ball.update();
    score.update(ball);

    playerPaddle.update();
    aiPaddle.update();

    window.clear();
    ball.render(window);
    playerPaddle.render(window);
    aiPaddle.render(window);
    score.render(window);
    window.display();
}
