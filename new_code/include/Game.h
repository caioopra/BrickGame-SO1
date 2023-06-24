#ifndef GAME_H
#define GAME_H
#include <png.h>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "EnemyShip.h"
#include "Keyboard.h"
#include "PlayerShip.h"
#include "Window.h"

__BEGIN_API

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

    void initializeVariables();
    void initWindow();

    bool running() { return _window.getWindow()->isOpen(); }

    void teste();
    void moveAll();
    void pollEvents();
    void update();
    void render();
};

__END_API

#endif
