#ifndef EnemyShip_h
#define EnemyShip_h

#include "Ship.h"
#include <png.h>
#include <SFML/Graphics.hpp>

class EnemyShip : public Ship {
public:
    EnemyShip(int id);
    ~EnemyShip() {};
    int mgetId() { return id; }
private:
    int id;
};

#endif
