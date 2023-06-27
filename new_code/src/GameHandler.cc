#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

std::shared_ptr<std::list<sf::Sprite>> GameHandler::_toDrawSprites;
std::shared_ptr<std::list<sf::Event>> GameHandler::_eventList;
std::shared_ptr<PlayerShip> GameHandler::_player;
std::shared_ptr<std::list<EnemyShip*>> GameHandler::_enemies;
int GameHandler::_score;
int GameHandler::_speed;
int GameHandler::_amount_killed;
bool GameHandler::_is_paused;

GameHandler::GameHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _toDrawSprites = std::make_shared<std::list<sf::Sprite>>();
    _eventList = std::make_shared<std::list<sf::Event>>();
    _player = std::make_shared<PlayerShip>();
    _enemies = std::make_shared<std::list<EnemyShip*>>();

    _score = 0;
    _speed = 1;
    _amount_killed = 0;
    _is_paused = false;

    for (int i = 0; i < 4; i++) {
        EnemyShip* enemy = new EnemyShip();
        enemy->_x = i%2 * 400;
        enemy->_y = i > 1 ? 0 : 400;
        enemy->getShipSprite()->setPosition(enemy->_x, enemy->_y);
        _enemies->push_back(enemy);
    }
    
}

void GameHandler::increaseScore() {
    std::cout << "GAME HANDLER INCREASING SCORE" << std::endl;
    _score += 100;
    increaseAmountKilled();
}

void GameHandler::increaseAmountKilled() {
    _amount_killed += 1;
    if (_amount_killed == 4 && _speed < 3) {
        _amount_killed = 0;
        _speed++;

        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _enemies->begin(); enemy != _enemies->end(); enemy++) {
            EnemyShip* enemyShip = *enemy;
            enemyShip->_velocidade++;
        }
    }
}

void GameHandler::pause() {
    _is_paused = true;
}

void GameHandler::unpause() {
    _is_paused = false;
}

void GameHandler::initialize() {
    std::cout << "GAME HANDLER INITIALIZED" << std::endl;
}

__END_API
