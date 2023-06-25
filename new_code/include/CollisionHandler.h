#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <memory>

#include "GameHandler.h"
#include "threading/traits.h"

__BEGIN_API

class CollisionHandler {
   public:
    CollisionHandler();

    void run();


    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }

   private:
    std::shared_ptr<GameHandler> _gameHandler;
};

__END_API

#endif