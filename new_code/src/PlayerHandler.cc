#include "../include/PlayerHandler.h"

__BEGIN_API

PlayerHandler::PlayerHandler() {
}

void PlayerHandler::run() {
    // std::cout << "RUNNING: PLAYER SHIP" << std::endl;
    while(!Config::isGameOver){
        // std::cout << "RUNNING: PLAYER SHIP" << std::endl;
        _gameHandler->_player->run();
        Thread::yield();
    }
}

__END_API
