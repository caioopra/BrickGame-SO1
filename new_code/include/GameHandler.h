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
#include "PlayerShip.h"
#include "Shot.h"
#include "threading/traits.h"

__BEGIN_API
class GameHandler {
   private:
   public:
    GameHandler();
    void initialize();

    std::list<EnemyShip> _enemyList;
    std::list<Shot> _playerShots;
    std::list<Shot> _enemyShots;
    std::list<sf::Sprite> _toDrawSprites;
};

__END_API

#endif
