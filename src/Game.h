// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "AudioManager.h"

class Game {
public:
    Game();  // Construtor
    void run();  // Loop principal do jogo

private:
    void processEvents();  // Processa eventos (como fechar a janela)
    void update();         // Atualiza a lógica do jogo (movimento do jogador)
    void render();         // Renderiza todos os objetos do jogo
    void initAudio();      // Inicializa o sistema de áudio

    sf::RenderWindow window;  // Janela do jogo
    Player player;            // Personagem do jogo
    AudioManager audioManager; // Gerenciador de áudio
};

#endif
