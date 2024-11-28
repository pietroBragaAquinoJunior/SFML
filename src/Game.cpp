#include "Game.h"
#include <GL/glu.h>
#include <iostream>
#include <algorithm>

Game::Game() : window(sf::VideoMode(800, 600), "Meu Jogo", sf::Style::Default), 
               is3DMode(false), rotationAngle(0.0f) {
    window.setFramerateLimit(60);
    setupGL();
    initAudio();
}

void Game::setupGL() {
    // Configuração básica
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    
    // Configuração da projeção
    glViewport(0, 0, window.getSize().x, window.getSize().y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)window.getSize().x / window.getSize().y, 0.1f, 100.0f);
    
    // Voltar para a matriz de modelo
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    float gameTime = gameClock.getElapsedTime().asSeconds();
    
    if (gameTime >= TRANSITION_TIME) {
        is3DMode = true;
        rotationAngle += 1.0f;
        if (rotationAngle >= 360.0f) {
            rotationAngle = 0.0f;
        }
    } else {
        is3DMode = false;
        player.update();
    }
}

void Game::render2D() {
    window.clear(sf::Color(135, 206, 235));
    player.render(window);
    
    // Se estiver próximo da transição, escurece a tela gradualmente
    if (gameClock.getElapsedTime().asSeconds() > TRANSITION_TIME - 1.0f) {
        float alpha = std::min(255.0f, (gameClock.getElapsedTime().asSeconds() - (TRANSITION_TIME - 1.0f)) * 255.0f);
        sf::RectangleShape fadeRect(sf::Vector2f(window.getSize().x, window.getSize().y));
        fadeRect.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));
        window.draw(fadeRect);
    }
    
    window.display();
}

void Game::render3D() {
    // Ativa o contexto OpenGL
    window.pushGLStates();
    window.setActive(true);
    
    // Limpa os buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Configuração de iluminação
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    // Posição da luz
    GLfloat lightPosition[] = { 0.0f, 5.0f, 5.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    // Propriedades da luz
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    
    // Reseta as matrizes
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)window.getSize().x / window.getSize().y, 0.1f, 100.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
    
    // Desenha um cubo com normais
    glBegin(GL_QUADS);
    
    // Face frontal (vermelha)
    glColor3f(1.0f, 0.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    
    // Face traseira (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // Face superior (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    // Face inferior (amarela)
    glColor3f(1.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    
    // Face direita (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // Face esquerda (ciano)
    glColor3f(0.0f, 1.0f, 1.0f);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    
    // Desabilita iluminação
    glDisable(GL_LIGHTING);
    
    // Restaura o estado do SFML
    window.popGLStates();
    window.display();
}

void Game::render() {
    if (!is3DMode) {
        render2D();
    } else {
        render3D();
    }
}

void Game::initAudio() {
    if (audioManager.loadMusic("resources/music/Scott-Holmes-Music-Empires.ogg")) {
        audioManager.setVolume(50.0f);
        audioManager.playMusic();
    }
}
