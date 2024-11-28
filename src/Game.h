// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include "Player.h"
#include "AudioManager.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void initAudio();
    void render2D();
    void render3D();
    void setupGL();
    void drawCube();

    sf::RenderWindow window;
    Player player;
    AudioManager audioManager;
    
    bool is3DMode;
    sf::Clock gameClock;
    static constexpr float TRANSITION_TIME = 5.0f;
    float rotationAngle;
};

#endif
