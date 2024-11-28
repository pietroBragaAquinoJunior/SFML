// Game.cpp
#include "Game.h"  // Inclua o cabeçalho para a classe Game

// Construtor de Game
Game::Game() : window(sf::VideoMode::getDesktopMode(), "Personagem Animado", sf::Style::Fullscreen) {
    if (!texture.loadFromFile("resources/personagem.png")) {
        // Lidar com erro de carregamento
        return;
    }
    sprite.setTexture(texture);

    // Redimensionar o sprite
    sprite.setScale(5.f, 5.f);  // Aumenta o sprite 4 vezes (ajuste conforme necessário)
    sprite.setPosition(300.f, 300.f);  // Posição ajustada para centralizar melhor
}

// Método para rodar o jogo
void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

// Processamento de eventos
void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

// Atualizações do jogo (lógica, animações, etc.)
void Game::update() {
    // Atualizar o jogo, lógica, física, animações
}

// Renderização (desenho na tela)
void Game::render() {
    window.clear(sf::Color(135, 206, 235));  // Cor do fundo (SkyBlue)
    window.draw(sprite);  // Desenha o sprite na tela
    window.display();
}
