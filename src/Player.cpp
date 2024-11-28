// Player.cpp
#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player() : speed(5.0f), frameTime(FRAME_TIME), currentFrameTime(0), 
                  currentFrame(0), frameCount(FRAMES_PER_ROW), isMoving(false), 
                  currentState("idle"), facingLeft(false), currentDirection(DOWN) {
    if (!texture.loadFromFile("resources/sprites/orc1_walk_full.png")) {
        // Lidar com erro de carregamento
        throw std::runtime_error("Falha ao carregar a textura do personagem!");
    }
    
    sprite.setTexture(texture);
    
    // Configurar o tamanho do sprite
    sprite.setScale(3.f, 3.f);
    
    // Posicionar no centro da tela
    position.x = 800/2.0f - (FRAME_WIDTH * sprite.getScale().x)/2.0f;
    position.y = 600/2.0f - (FRAME_HEIGHT * sprite.getScale().y)/2.0f;
    sprite.setPosition(position);
    
    // Configurar o retângulo de frame inicial
    frameRect = sf::IntRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT);
    sprite.setTextureRect(frameRect);
}

void Player::update() {
    handleInput();
    updateAnimation();
    sprite.setPosition(position);
}

void Player::updateAnimation() {
    currentFrameTime += 1.0f/60.0f; // Assumindo 60 FPS
    
    if (currentFrameTime >= frameTime) {
        currentFrameTime = 0;
        
        if (isMoving) {
            currentFrame = (currentFrame + 1) % frameCount;
            frameRect.left = currentFrame * FRAME_WIDTH;
            frameRect.top = currentDirection * FRAME_HEIGHT; // Seleciona a linha correta do sprite
            sprite.setTextureRect(frameRect);
        }
    }
}

void Player::handleInput() {
    isMoving = false;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= speed;
        isMoving = true;
        currentDirection = LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += speed;
        isMoving = true;
        currentDirection = RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= speed;
        isMoving = true;
        currentDirection = UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position.y += speed;
        isMoving = true;
        currentDirection = DOWN;
    }
    
    if (!isMoving) {
        currentFrame = 0;
        frameRect.left = 0;
        frameRect.top = currentDirection * FRAME_HEIGHT; // Mantém a direção atual quando parado
        sprite.setTextureRect(frameRect);
    }
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
