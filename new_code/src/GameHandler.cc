#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

std::shared_ptr<std::list<sf::Sprite>> GameHandler::_toDrawSprites;
std::shared_ptr<std::list<sf::Event>> GameHandler::_eventList;
std::shared_ptr<PlayerShip> GameHandler::_player;
std::shared_ptr<std::list<EnemyShip*>> GameHandler::_enemies;

GameHandler::GameHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _toDrawSprites = std::make_shared<std::list<sf::Sprite>>();
    _eventList = std::make_shared<std::list<sf::Event>>();
    _player = std::make_shared<PlayerShip>();
    _enemies = std::make_shared<std::list<EnemyShip*>>();

    for (int i = 0; i < 4; i++) {
        EnemyShip* enemy = new EnemyShip();
        enemy->_x = i%2 * 400;
        enemy->_y = i > 1 ? 0 : 400;
        enemy->getShipSprite()->setPosition(enemy->_x, enemy->_y);
        _enemies->push_back(enemy);
    }
    
}

void GameHandler::initialize() {
    std::cout << "GAME HANDLER INITIALIZED" << std::endl;
}

__END_API
