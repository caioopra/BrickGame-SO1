#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <list>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "keyboard.h"
#include "CollisionHandler.h"
class Game {
public:
    Game();
    void init();
    void run();

    PlayerShip* getPlayer() { return _player_ship; }
    std::list<EnemyShip*> getEnemies() { return _enemies_list; }
    Keyboard* getKeyboard() { return _keyboard; }
    CollisionHandler* getCollisionHandler() { return _collision; }

protected:
    bool gameOver;
    bool spawnEnemies;

    int score;    
    int speed;

    PlayerShip* _player_ship;
    std::list<EnemyShip*> _enemies_list;
    
    Keyboard* _keyboard;
    CollisionHandler* _collision;
};

#endif
