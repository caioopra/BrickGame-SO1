#include "../include/EnemiesHandler.h"
#include "../include/TimeHandler.h"

__BEGIN_API

TimeHandler timeHandler2 = TimeHandler();

EnemiesHandler::EnemiesHandler() {

}

void EnemiesHandler::run() {
    while (!Config::isGameOver) {
        std::cout << "RUNNING: ENEMIES HANDLER" << std::endl;

        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
            if(timeHandler2.enemyCanShot()){
            myEnemy->createShot();
            }
            enemy++;
        }
        

        Thread::yield();
    }
}


__END_API