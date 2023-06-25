#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "Shot.h"


class GameHandler {
private:

public:
    GameHandler();
    ~GameHandler();
    std::shared_ptr<PlayerShip> _player;
    std::list<std::shared_ptr<EnemyShip>> _enemyList;
    std::list<std::shared_ptr<Shot>> _playerShots;
    std::list<std::shared_ptr<Shot>> _enemyShots;
    std::list<std::shared_ptr<sf::Sprite>> _toDrawSprites;

};

#endif
