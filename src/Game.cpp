#include "Game.hpp"
#include <iostream>

// Constructor de la clase Game
Game::Game()
    : window(sf::VideoMode(800, 600), "Pong"),  // Inicializar la ventana del juego
      ball(10.f, 400.f, 300.f),  // Inicializar la pelota
      playerPaddle(10.f, 250.f, 10.f, 100.f, 300.f),  // Inicializar el paddle del jugador
      aiPaddle(770.f, 250.f, 10.f, 100.f, 300.f, ball),  // Inicializar el paddle de la IA
      playerScore(0), aiScore(0), timeSinceLastPoint(0.f) {  // Inicializar las puntuaciones y el temporizador

    // Cargar la fuente para el texto
    if (!font.loadFromFile("assets/fonts/ds_digital/DS-DIGIB.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Configurar el texto del marcador del jugador
    playerScoreText.setFont(font);
    playerScoreText.setCharacterSize(48); // Aumentar tamaño del texto
    playerScoreText.setFillColor(sf::Color::Red); // Cambiar color del texto a rojo
    playerScoreText.setPosition(300, 10); // Centrar el texto horizontalmente

    // Configurar el texto del marcador del AI
    aiScoreText.setFont(font);
    aiScoreText.setCharacterSize(48); // Aumentar tamaño del texto
    aiScoreText.setFillColor(sf::Color::Red); // Cambiar color del texto a rojo
    aiScoreText.setPosition(475, 10); // Centrar el texto horizontalmente

    // Configurar etiquetas de puntaje
    playerLabel.setFont(font);
    playerLabel.setCharacterSize(48);
    playerLabel.setFillColor(sf::Color::Red);
    playerLabel.setPosition(50, 10);
    playerLabel.setString("JUGADOR");

    aiLabel.setFont(font);
    aiLabel.setCharacterSize(48);
    aiLabel.setFillColor(sf::Color::Red);
    aiLabel.setPosition(710, 10);
    aiLabel.setString("AI");

    // Configurar el texto de cuenta regresiva
    countdownText.setFont(font);
    countdownText.setCharacterSize(30);
    countdownText.setFillColor(sf::Color::Red);
    countdownText.setPosition(300, 550);

    // Cargar la textura de fondo
    if (!backgroundTexture.loadFromFile("assets/images/tenniscourtblue.png")) {
        std::cerr << "Error loading background image" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    // Cargar textura para el paddle del jugador
    if (!playerPaddleTexture.loadFromFile("assets/images/PlayerPaddle.png")) {
        std::cerr << "Error loading player paddle texture" << std::endl;
    }
    playerPaddle.setTexture(playerPaddleTexture);

    // Cargar textura para el paddle de la IA
    if (!aiPaddleTexture.loadFromFile("assets/images/AIPaddle.png")) {
        std::cerr << "Error loading AI paddle texture" << std::endl;
    }
    aiPaddle.setTexture(aiPaddleTexture);

    // Cargar el sonido de colisión
    if (!collisionBuffer.loadFromFile("assets/sounds/pongsound.ogg")) {
        std::cerr << "Error loading collision sound" << std::endl;
    }
    collisionSound.setBuffer(collisionBuffer);
}

// Método principal para ejecutar el bucle del juego
void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();  // Procesar eventos de entrada del usuario
        float deltaTime = clock.restart().asSeconds();  // Calcular el tiempo transcurrido
        update(deltaTime);  // Actualizar el estado del juego
        render();  // Renderizar los elementos del juego
    }
}

// Método para procesar eventos de entrada del usuario
void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();  // Cerrar la ventana si se recibe un evento de cierre
    }
}

// Método para actualizar el estado del juego
void Game::update(float deltaTime) {
    // Cerrar la ventana si algún jugador alcanza 5 puntos
    if (playerScore >= 5 || aiScore >= 5) {
        window.close();
        return;
    }

    timeSinceLastPoint += deltaTime;

    // Incrementar la puntuación del jugador cada 20 segundos
    if (timeSinceLastPoint >= 20.f) {
        playerScore++;
        ball.setPosition(400.f, 300.f);
        ball.setVelocity(-350.f, -350.f);
        timeSinceLastPoint = 0.f;
    }

    playerPaddle.update(deltaTime);  // Actualizar el paddle del jugador
    aiPaddle.update(deltaTime);  // Actualizar el paddle de la IA
    ball.update(deltaTime, playerPaddle, aiPaddle);  // Actualizar la pelota

    // Verificar colisiones y reproducir sonido
    if (ball.getBounds().intersects(playerPaddle.getBounds()) ||
        ball.getBounds().intersects(aiPaddle.getBounds())) {
        collisionSound.play();
    }

    // Actualizar la puntuación y reiniciar la posición de la pelota
    if (ball.getPosition().x < 0) {
        aiScore++;
        ball.setPosition(400.f, 300.f);
        ball.setVelocity(350.f, 350.f);
        timeSinceLastPoint = 0.f; // Reiniciar el temporizador al marcar un punto
    } else if (ball.getPosition().x + ball.getBounds().width > 800) {
        playerScore++;
        ball.setPosition(400.f, 300.f);
        ball.setVelocity(-350.f, -350.f);
        timeSinceLastPoint = 0.f; // Reiniciar el temporizador al marcar un punto
    }

    // Actualizar texto de cuenta regresiva
    countdownText.setString("Tiempo restante: " + std::to_string(static_cast<int>(20.f - timeSinceLastPoint)));

    // Actualizar texto de puntuación
    playerScoreText.setString(std::to_string(playerScore));
    aiScoreText.setString(std::to_string(aiScore));
}

// Método para renderizar los elementos del juego
void Game::render() {
    window.clear();  // Limpiar la ventana
    window.draw(backgroundSprite);  // Dibujar el fondo
    playerPaddle.draw(window);  // Dibujar el paddle del jugador
    aiPaddle.draw(window);  // Dibujar el paddle de la IA
    ball.render(window);  // Renderizar la pelota
    window.draw(playerScoreText);  // Dibujar el texto de puntuación del jugador
    window.draw(aiScoreText);  // Dibujar el texto de puntuación de la IA
    window.draw(countdownText);  // Dibujar el texto de cuenta regresiva
    window.draw(playerLabel);  // Dibujar la etiqueta del jugador
    window.draw(aiLabel);  // Dibujar la etiqueta de la IA
    window.display();  // Mostrar los elementos renderizados en la ventana
}