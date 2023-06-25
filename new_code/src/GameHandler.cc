#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

std::shared_ptr<std::list<sf::Sprite>> GameHandler::_toDrawSprites;
std::shared_ptr<std::list<sf::Event>> GameHandler::_eventList;
std::shared_ptr<PlayerShip> GameHandler::_player;

GameHandler::GameHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _toDrawSprites = std::make_shared<std::list<sf::Sprite>>();
    _eventList = std::make_shared<std::list<sf::Event>>();
    _player = std::make_shared<PlayerShip>();
}

void GameHandler::initialize() {
    std::cout << "GAME HANDLER INITIALIZED" << std::endl;
}

__END_API
