#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/TimeHandler.h"

__BEGIN_API

std::shared_ptr<sf::Clock> TimeHandler::_playerClock;
std::shared_ptr<sf::Clock> TimeHandler::_enemiesClock;

TimeHandler::TimeHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _playerClock = std::make_shared<sf::Clock>();
    _enemiesClock = std::make_shared<sf::Clock>();
}


bool TimeHandler::playerCanShot() {
    sf::Time newTime = _playerClock->getElapsedTime();
    if (newTime.asMilliseconds()>500){
        std::cout << "\n\nTIME HANDLER PLAYER CAN SHOT" << std::endl;
        std::cout << newTime.asMilliseconds() << std::endl;
        std::cout << "TIME HANDLER PLAYER CAN SHOT\n\n" << std::endl;
        _playerClock->restart();
        return true;
    }else{
        return false;
    }
}

bool TimeHandler::enemyCanShot() {
    sf::Time newTime = _enemiesClock->getElapsedTime();
    if (newTime.asMilliseconds()>500){
        std::cout << "\n\nTIME HANDLER PLAYER CAN SHOT" << std::endl;
        std::cout << newTime.asMilliseconds() << std::endl;
        std::cout << "TIME HANDLER PLAYER CAN SHOT\n\n" << std::endl;
        _enemiesClock->restart();
        return true;
    }else{
        std::cout << "\n\nTIME HANDLER PLAYER CAN SHOT NAO ATIROUUUUUUUUUUUUUUUU" << std::endl;
        std::cout << newTime.asMilliseconds() << std::endl;
        std::cout << "TIME HANDLER PLAYER CAN SHOT\n\n" << std::endl;
        return false;
    }
}


__END_API
