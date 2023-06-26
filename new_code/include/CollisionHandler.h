#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <list>
#include <memory>

#include "EnemyShip.h"
#include "GameHandler.h"
#include "PlayerShip.h"
#include "Ship.h"
#include "Shot.h"
#include "threading/thread.h"
#include "threading/traits.h"

__BEGIN_API

class CollisionHandler {
   public:
    CollisionHandler();

    void run();

    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }

    void checkBorderCollision();
    void checkBorderCollisionShot();
    bool checkCollisionBullet(EnemyShip* enemy, std::list<Shot*>* bullets);
    bool checkCollisionBullet(PlayerShip* enemy, std::list<Shot*>* bullets);

    int getFuturePosition();

   private: 
    std::shared_ptr<GameHandler> _gameHandler;
};

__END_API

#endif