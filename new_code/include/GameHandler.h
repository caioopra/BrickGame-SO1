#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <png.h>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

#include "EnemyShip.h"
#include "Ship.h"
#include "PlayerShip.h"
#include "Shot.h"
#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API
class GameHandler {
   private:

   public:
    GameHandler();
    void initialize();

    static std::shared_ptr<std::list<sf::Sprite>> _toDrawSprites;
};

__END_API

#endif
