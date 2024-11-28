// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game(); // Construtor
    void run(); // Método para iniciar e rodar o jogo

private:
    void processEvents(); // Processamento de eventos
    void update();        // Atualizar o jogo (logica, física, etc.)
    void render();        // Desenhar os objetos na tela

    sf::RenderWindow window; // Janela do jogo
    sf::Sprite sprite;       // Personagem (sprite)
    sf::Texture texture;     // Textura do sprite
};

#endif
