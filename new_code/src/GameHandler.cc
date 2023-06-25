#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/GameHandler.h"

__BEGIN_API

GameHandler::GameHandler() {
    std::cout << "hello" << std::endl;
}

void GameHandler::initialize() {
    std::cout << "GAME HANDLER INITIALIZED" << std::endl;
}

__END_API
