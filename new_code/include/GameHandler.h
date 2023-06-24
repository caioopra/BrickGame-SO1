#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "Shot.h"


class GameHandler {
private:
    static PlayerShip _player;
    static std::list <EnemyShip> _enemyList;
    static std::list <Shot> _playerShots;
    static std::list <Shot> _enemyShots;
    static std::list <sf::Sprite> _toDrawSprites;

public:
    GameHandler();
    ~GameHandler();
};

#endif
