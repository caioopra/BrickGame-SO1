#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/TimeHandler.h"

__BEGIN_API

std::shared_ptr<sf::Clock> TimeHandler::_playerClock;
std::shared_ptr<sf::Clock> TimeHandler::_enemiesClock;
std::shared_ptr<sf::Clock> TimeHandler::_enemiesMoveClock;

TimeHandler::TimeHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _playerClock = std::make_shared<sf::Clock>();
    _enemiesClock = std::make_shared<sf::Clock>();
    _enemiesMoveClock = std::make_shared<sf::Clock>();
    contador = 0;
    contadorMove = 0;
}


bool TimeHandler::playerCanShot() {
    sf::Time newTime = _playerClock->getElapsedTime();
    if (newTime.asMilliseconds()>500){

        _playerClock->restart();

        return true;
    }else{
        return false;
    }
}

bool TimeHandler::enemyCanShot() {
    sf::Time newTime = _enemiesClock->getElapsedTime();
    if (newTime.asMilliseconds()>500){
        contador++;
        if(contador == 3){
        _enemiesClock->restart();
        contador=0;
        }
        return true;
    }else{

        return false;
    }
}

bool TimeHandler::enemyCanMove() {
    sf::Time newTime = _enemiesMoveClock->getElapsedTime();
    // std::cout << newTime.asMilliseconds() << std::endl;
    if (newTime.asMilliseconds()>500){
        contadorMove++;
        if(contador == 3){
            newTime = _enemiesMoveClock->restart();
            contadorMove=0;
        }
        return true;
    }else{
        return false;
    }
}

__END_API
