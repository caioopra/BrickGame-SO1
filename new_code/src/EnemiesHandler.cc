#include "../include/EnemiesHandler.h"

__BEGIN_API

EnemiesHandler::EnemiesHandler() {

}

void EnemiesHandler::run() {
    while (!Config::isGameOver) {
        std::cout << "RUNNING: ENEMIES HANDLER" << std::endl;
        Thread::yield();
    }
}


__END_API