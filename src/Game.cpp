#include "Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong"), 
      ball(10.f, 400.f, 300.f), 
      playerPaddle(20.f, 250.f, 10.f, 100.f, 300.f), 
      aiPaddle(770.f, 250.f, 10.f, 100.f, 300.f, ball),
      playerScore(0), aiScore(0) {

    if (!font.loadFromFile("assets/fonts/ds_digital/DS-DIGI.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }

    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(24);
    playerScoreText.setFillColor(sf::Color::White);
    playerScoreText.setPosition(10, 10);

    aiScoreText.setFont(font);
    aiScoreText.setCharacterSize(24);
    aiScoreText.setFillColor(sf::Color::White);
    aiScoreText.setPosition(760, 10);

    if (!backgroundTexture.loadFromFile("assets/images/tenniscourt.png")) {
        std::cerr << "Error loading background image" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    // Cargar el sonido de colisión
    if (!collisionBuffer.loadFromFile("assets/sounds/pongsound.ogg")) {
        std::cerr << "Error loading collision sound" << std::endl;
    }
    collisionSound.setBuffer(collisionBuffer);
}

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
    ball.update(deltaTime, playerPaddle, aiPaddle);

    // Verificar colisiones y reproducir sonido
    if (ball.getBounds().intersects(playerPaddle.getBounds()) ||
        ball.getBounds().intersects(aiPaddle.getBounds())) {
        collisionSound.play();
    }

    if (ball.getPosition().x < 0) {
        aiScore++;
        ball.setPosition(400.f, 300.f);
        ball.setVelocity(350.f, 350.f);
    } else if (ball.getPosition().x + ball.getBounds().width > 800) {
        playerScore++;
        ball.setPosition(400.f, 300.f);
        ball.setVelocity(-350.f, -350.f);
    }

    playerScoreText.setString(std::to_string(playerScore));
    aiScoreText.setString(std::to_string(aiScore));
}

void Game::render() {
    window.clear();
    window.draw(backgroundSprite);
    playerPaddle.draw(window);
    aiPaddle.draw(window);
    ball.render(window);
    window.draw(playerScoreText);
    window.draw(aiScoreText);
    window.display();
}