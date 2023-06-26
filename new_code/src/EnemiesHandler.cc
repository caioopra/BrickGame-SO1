#include "../include/EnemiesHandler.h"

__BEGIN_API

EnemiesHandler::EnemiesHandler() {

}

void EnemiesHandler::run() {
    while (!Config::isGameOver) {
        std::cout << "RUNNING: ENEMIES HANDLER" << std::endl;

        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
            myEnemy->createShot();
            enemy++;
        }

        Thread::yield();
    }
}


__END_API