#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H
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
#include "Keyboard.h"
#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API
class TimeHandler {
   private:

   public:
    TimeHandler();
    void initialize();
    bool playerCanShot();
    bool enemyCanShot();

    static std::shared_ptr<sf::Clock> _playerClock;
    static std::shared_ptr<sf::Clock> _enemiesClock;
    int contador = 0;
};

__END_API

#endif
