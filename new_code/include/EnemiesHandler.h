#ifndef ENEMIESHANDLER_H
#define ENEMIESHANDLER_H

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameHandler.h"
#include "Ship.h"
#include "threading/traits.h"
#include "threading/thread.h"
#include "Config.h"

__BEGIN_API

class EnemiesHandler{
   public:
    EnemiesHandler();
    ~EnemiesHandler(){};

    void run();
    void moveEnemies();
    void colisionBorder();
    void colisionEnemies();
    void colisionEnemies2();

    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }

   private:
    std::shared_ptr<GameHandler> _gameHandler;
};

__END_API

#endif
