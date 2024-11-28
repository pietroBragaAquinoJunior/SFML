// Game.cpp
#include "Game.h"

Game::Game() : window(sf::VideoMode::getDesktopMode(), "Personagem Animado", sf::Style::Fullscreen) {
    // Inicialização do jogo (janela, etc.)
    window.setFramerateLimit(60);
    initAudio();
}

void Game::initAudio() {
    // Carrega e inicia a música de fundo
    if (audioManager.loadMusic("resources/music/Scott-Holmes-Music-Empires.ogg")) {
        audioManager.setVolume(50.0f); // Volume a 50%
        audioManager.playMusic();
    }
}

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
    player.update();  // Atualiza a movimentação do jogador
}

void Game::render() {
    window.clear(sf::Color(135, 206, 235));  // Cor de fundo
    player.render(window);  // Desenha o personagem
    window.display();  // Exibe tudo na janela
}
