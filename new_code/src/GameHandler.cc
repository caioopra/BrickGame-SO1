#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

std::shared_ptr<std::list<sf::Event>> GameHandler::_eventList;
std::shared_ptr<PlayerShip> GameHandler::_player;
std::shared_ptr<std::list<EnemyShip*>> GameHandler::_enemies;
std::shared_ptr<std::list<EnemyShip*>> GameHandler::_enemiesDead;
int GameHandler::_score;
int GameHandler::_speed;
int GameHandler::_amount_killed;
bool GameHandler::_is_paused;
bool GameHandler::_is_over;
bool GameHandler::_movementType;

class EnemyShip;

GameHandler::GameHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _eventList = std::make_shared<std::list<sf::Event>>();
    _player = std::make_shared<PlayerShip>();
    _enemies = std::make_shared<std::list<EnemyShip*>>();
    _enemiesDead = std::make_shared<std::list<EnemyShip*>>();

    _score = 0;
    _speed = 1;
    _amount_killed = 0;
    _is_paused = false;
    _movementType = true;
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

void GameHandler::reset() {
    _score = 0;
    _speed = 1;
    _amount_killed = 0;
    _is_over = false;
    _movementType = !_movementType;

    std::list<EnemyShip*>::iterator enemy;
    for (enemy = _enemies->begin(); enemy != _enemies->end(); enemy++) {
        EnemyShip* enemyShip = *enemy;
        enemyShip->_x = enemyShip->initial_x;
        enemyShip->_y = enemyShip->initial_y;
        enemyShip->_shots->clear();
    }
    
    _player->_shots->clear();
    _player->_x = 200;
    _player->_y = 200;
    _player->vidas = 3;
}

__END_API
