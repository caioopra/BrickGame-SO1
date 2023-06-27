#include "../include/Game.h"
#include <iostream>

__BEGIN_API

Game::Game(){
    std::cout << "Game instanciated" << std::endl;
}

void Game::run() {
    while(!(_config.isGameOver)){

        Thread::yield();
    }
}



__END_API
