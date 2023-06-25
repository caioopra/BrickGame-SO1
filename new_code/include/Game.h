#ifndef GAME_H
#define GAME_H

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Config.h"
#include "EnemyShip.h"
#include "GameHandler.h"
#include "Keyboard.h"
#include "PlayerShip.h"
#include "Window.h"
#include "threading/traits.h"
#include "Config.h"

__BEGIN_API

class Game {
   private:
    std::shared_ptr<GameHandler> _gameHandler;
    sf::Event _event;
    Window _window;
    Keyboard _keyboard;
    Config _config;

   public:
    Game();
    void initializeVariables();
    void initWindow();

    void run();
    void moveAll();
    void pollEvents();
    void update();
    void render();

    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }
};

__END_API

#endif
