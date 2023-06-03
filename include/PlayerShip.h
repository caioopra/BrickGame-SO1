#ifndef PlayerShip_h
#define PlayerShip_h

#include "Ship.h"
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>

class PlayerShip : public Ship {
public:
    PlayerShip(int id);  
    ~PlayerShip() {};
    int mgetId() { return id;}
private:
    int id;
};


#endif
