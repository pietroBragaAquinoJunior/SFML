//
// Created by pietr on 27/11/2024.
//

// COMPILAÇÃO:
// g++ -Wall -Wextra -Werror src/main.cpp src/Game.cpp -o build/app.exe -lsfml-graphics -lsfml-window -lsfml-system
// .\build\app.exe

// main.cpp
#include "Game.h"

int main() {
    Game game; // Criar o objeto do jogo
    game.run(); // Rodar o jogo
    return 0;
}
