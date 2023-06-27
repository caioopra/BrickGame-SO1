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
#include "Keyboard.h"
#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API
class GameHandler {
   private:

   public:
    GameHandler();
    void initialize();
    void reset();

    static std::shared_ptr<PlayerShip> _player;
    static std::shared_ptr<std::list<EnemyShip*>> _enemies;
    static std::shared_ptr<std::list<EnemyShip*>> _enemiesDead;
    static std::shared_ptr<std::list<sf::Event>> _eventList;

    static int _score;
    static int _speed;
    static int _amount_killed;
    static bool _is_paused;
    static bool _is_over;

    static void increaseScore();
    static void increaseAmountKilled();
    static void pause();
    static void unpause();
};

__END_API

#endif
