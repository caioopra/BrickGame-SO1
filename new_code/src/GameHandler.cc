#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"


GameHandler::GameHandler(){
    EnemyShip firstEnemy;
    firstEnemy.getShipSprite()->setPosition(200,200);
    _enemyList.push_back(firstEnemy);
}
