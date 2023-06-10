#ifndef PlayerShip_h
#define PlayerShip_h

#include "Ship.h"
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>


class PlayerShip : public Ship {
public:
    PlayerShip();  
    ~PlayerShip() {};
private:
    int vidas = 3;
};


#endif
