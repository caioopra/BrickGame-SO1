#include "../include/PlayerHandler.h"

__BEGIN_API

PlayerHandler::PlayerHandler() {
}

void PlayerHandler::run() {
    // std::cout << "RUNNING: PLAYER SHIP" << std::endl;
    _gameHandler->_toDrawSprites->push_back(*_gameHandler->_player->getShipSprite());
    while(!Config::isGameOver){
        // std::cout << "RUNNING: PLAYER SHIP" << std::endl;
        _gameHandler->_player->run();
        Thread::yield();
    }
}

__END_API
