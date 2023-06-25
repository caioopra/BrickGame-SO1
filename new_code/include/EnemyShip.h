#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <png.h>

#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "threading/traits.h"

__BEGIN_API
class EnemyShip : public Ship {
   public:
    EnemyShip();

   private:
    int movimentation = 0;
};

__END_API

#endif
