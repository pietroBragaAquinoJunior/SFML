// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();  // Construtor
    void update();  // Atualiza o movimento do personagem
    void render(sf::RenderWindow& window);  // Renderiza o personagem na tela
    void handleInput();  // Lida com a entrada do teclado (movimentação)

private:
    sf::Sprite sprite;       // Personagem (sprite)
    sf::Texture texture;     // Textura do sprite
    sf::Vector2f position;   // Posição do personagem
    float speed;             // Velocidade de movimento
};

#endif
