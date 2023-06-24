#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "Keyboard.h" 
#include "Window.h"

class Game {
private:
    sf::Event _event;
    Window _window;
    PlayerShip _player;
    EnemyShip _enemy1;
    EnemyShip _enemy2;
    EnemyShip _enemy3;
    EnemyShip _enemy4;

    Keyboard _keyboard;

public:
    Game();
    ~Game();

    int _positions[10];

    void initializeVariables();
    void initWindow();

    bool running() { return _window.isOpen(); }

    void teste();
    void moveAll();
    void pollEvents();
    void update();
    void render();
};

#endif
