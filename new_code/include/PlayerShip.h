#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameHandler.h"
#include "Ship.h"
#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API

class PlayerShip : public Ship {
   public:
    PlayerShip();
    ~PlayerShip(){};

    void run();

    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }

   private:
    int vidas = 3;
    std::shared_ptr<GameHandler> _gameHandler;
};

__END_API

#endif
