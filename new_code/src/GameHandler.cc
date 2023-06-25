#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"


PlayerShip GameHandler::_player;
std::list <EnemyShip> GameHandler::_enemyList;
std::list <Shot> GameHandler::_playerShots;
std::list <Shot> GameHandler::_enemyShots;
std::list <sf::Sprite> GameHandler::_toDrawSprites;

GameHandler::GameHandler() {
    EnemyShip firstEnemy;
    firstEnemy.getShipSprite()->setPosition(200,200);
    _enemyList.push_back(firstEnemy);
}
