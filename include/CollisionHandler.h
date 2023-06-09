#ifndef COLIISIONHANDLER_H
#define COLIISIONHANDLER_H

#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
#include "EnemyShip.h"

class CollisionHandler {
public:
    CollisionHandler(PlayerShip* player, EnemyShip* enemy);

    bool checkIfWillCollide(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2);
    int getFuturePosition();
    bool checkCollision(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2); 


private:
    PlayerShip* _player;
    EnemyShip* _enemy; // mudar para ser a lista de inimigos

};


#endif
