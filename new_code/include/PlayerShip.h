#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Ship.h"
#include "threading/traits.h"
#include "threading/thread.h"
#include "Config.h"

__BEGIN_API

class PlayerShip : public Ship {
   public:
    PlayerShip();
    ~PlayerShip(){};

    void run();

   private:
    int vidas = 3;

};

__END_API

#endif
