#include "../include/EnemiesHandler.h"
#include "../include/TimeHandler.h"

__BEGIN_API

TimeHandler timeHandler2 = TimeHandler();

EnemiesHandler::EnemiesHandler() {

}

void EnemiesHandler::run() {
    while (!Config::isGameOver) {
        std::cout << "RUNNING: ENEMIES HANDLER" << std::endl;
        moveEnemies();

        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
            if(timeHandler2.enemyCanShot()){
            myEnemy->createShot();
            }
            myEnemy->_ship_sprite.setPosition(myEnemy->_x, myEnemy->_y);
            enemy++;
        }
        

        Thread::yield();
    }
}

void EnemiesHandler::moveEnemies() {
        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
            if (myEnemy->getDirection() == Ship::UP) {
                if (myEnemy->_y - myEnemy->_velocidade > 0) { 
                    std::cout << "MOVENDOOOOOOOOOOOOOOO"<< std::endl;
                    myEnemy->move();
                }else{
                    myEnemy->changeDirection(Ship::DOWN);
                }
            } else if (myEnemy->getDirection() == Ship::DOWN) {
                if (myEnemy->_y + myEnemy->_velocidade < 512) { 
                    std::cout << "MOVENDOOOOOOOOOOOOOOO"<< std::endl;
                    myEnemy->move();
                }else{
                    myEnemy->changeDirection(Ship::UP);
                }
            } else if (myEnemy->getDirection() == Ship::RIGHT) {
                if (myEnemy->_x + myEnemy->_velocidade < 512) { 
                    std::cout << "MOVENDOOOOOOOOOOOOOOO"<< std::endl;
                    myEnemy->move();
                }else{
                    myEnemy->changeDirection(Ship::LEFT);
                }
            } else {
                if (myEnemy->_x - myEnemy->_velocidade > 0) {
                    std::cout << "MOVENDOOOOOOOOOOOOOOO"<< std::endl;
                    myEnemy->move();
                }else{
                    myEnemy->changeDirection(Ship::RIGHT);
                }
            }
            enemy++;
        }
    }


__END_API