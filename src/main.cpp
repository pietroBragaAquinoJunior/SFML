//
// Created by pietr on 27/11/2024.
//

// COMPILAÇÃO:
//  g++ -Wall -Wextra -Werror src/main.cpp src/Game.cpp src/Player.cpp -o build/app.exe -lsfml-graphics -lsfml-window -lsfml-system
// .\build\app.exe

// main.cpp
#include "Game.h"

int main() {
    try {
        Game game;  // Cria uma instância do jogo
        game.run(); // Inicia o loop do jogo
    } catch (const std::exception& e) {
        // Lida com exceções (como falha ao carregar recursos)

    }
    return 0;
}
