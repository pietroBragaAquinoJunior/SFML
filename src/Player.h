// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string> // Adicionado para suportar std::string

class Player {
public:
    Player();  // Construtor
    void update();  // Atualiza o movimento do personagem
    void render(sf::RenderWindow& window);  // Renderiza o personagem na tela
    void handleInput();  // Lida com a entrada do teclado (movimentação)

private:
    void updateAnimation();
    void setCurrentAnimation(const std::string& state);

    sf::Sprite sprite;       // Personagem (sprite)
    sf::Texture texture;     // Textura do sprite
    sf::Vector2f position;   // Posição do personagem
    float speed;             // Velocidade de movimento

    // Animação
    sf::IntRect frameRect;
    float frameTime;
    float currentFrameTime;
    int currentFrame;
    int frameCount;
    bool isMoving;
    std::string currentState;
    bool facingLeft;
    
    // Constantes de animação
    static constexpr float FRAME_TIME = 0.1f;  // Tempo entre frames
    static constexpr int FRAME_WIDTH = 64;     // Largura de cada frame
    static constexpr int FRAME_HEIGHT = 64;    // Altura de cada frame
    static constexpr int FRAMES_PER_ROW = 6;   // Frames por linha
    
    // Direções de animação (linhas do sprite)
    enum Direction {
        DOWN = 0,      // Primeira linha
        UP = 1,        // Segunda linha
        LEFT = 2,      // Terceira linha
        RIGHT = 3      // Quarta linha
    };
    Direction currentDirection;
};

#endif
