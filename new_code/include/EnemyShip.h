#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <png.h>

#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "threading/traits.h"
#include "threading/thread.h"
#include <memory>
#include "Config.h"

__BEGIN_API
class EnemyShip : public Ship {
   public:
    EnemyShip(int movement, int x, int y);
    void run();
 
    void setDead(bool state) { _dead = state; }
    sf::Clock getReviveClock() { return _revive_clock; }
 
    bool _dead = false;
    int initial_x, initial_y;

    sf::Clock _revive_clock;
    int _movement_algorithm;
   private:

};

__END_API

#endif
