#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

std::shared_ptr<std::list<sf::Sprite>> GameHandler::_toDrawSprites;

GameHandler::GameHandler() {
    std::cout << "GAME HANDLER created" << std::endl;
    _toDrawSprites = std::make_shared<std::list<sf::Sprite>>();
    // _player = std::make_shared<PlayerShip>();
}

void GameHandler::initialize() {
    std::cout << "GAME HANDLER INITIALIZED" << std::endl;
}

__END_API
