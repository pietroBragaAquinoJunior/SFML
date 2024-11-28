// Player.cpp
#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : position(200.f, 200.f), speed(5.f) {
    // Carregar a textura do personagem
    if (!texture.loadFromFile("resources/personagem.png")) {
        // Erro ao carregar a textura
        throw std::runtime_error("Falha ao carregar a textura do personagem!");
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Player::update() {
    handleInput();  // Lida com o movimento com as teclas de seta

    // Atualiza a posição do sprite
    sprite.setPosition(position);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);  // Desenha o sprite na tela
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= speed;  // Move para cima
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position.y += speed;  // Move para baixo
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= speed;  // Move para a esquerda
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += speed;  // Move para a direita
    }
}
