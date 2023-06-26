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


void EnemiesHandler::colisionEnemies() {
    int x1, x2, y1, y2, width1, height1, width2, height2;
    bool colisao_1, colisao_2, colisao;
    std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
                std::list<EnemyShip*>::iterator enemy_2;
                for (enemy_2 = _gameHandler->_enemies->begin(); enemy_2 !=_gameHandler->_enemies->end();) {
                    EnemyShip* myEnemy_2= *enemy_2;
                    
                    x1 = myEnemy->getShipSprite()->getGlobalBounds().left;
                    y1 = myEnemy->getShipSprite()->getGlobalBounds().top;
                    width1 = myEnemy->getShipSprite()->getGlobalBounds().width;
                    height1 = myEnemy->getShipSprite()->getGlobalBounds().height;
                    x2 = myEnemy_2->getShipSprite()->getGlobalBounds().left;
                    y2 = myEnemy_2->getShipSprite()->getGlobalBounds().top;
                    width2 = myEnemy_2->getShipSprite()->getGlobalBounds().width;
                    height2 = myEnemy_2->getShipSprite()->getGlobalBounds().height;
                    colisao_1 = ((y1 > y2) && (y1 < y2 + height2)) || ((y1 + height1 > y2) && (y1 + height1 < y2 + height2));
                    colisao_2 = ((x1 > x2) && (x1 < x2 + width2)) || ((x1 + width1 > x2) && (x1 + width1 < x2 + width2));
                    colisao = colisao_1 && colisao_2;

                    std::cout << colisao << std::endl;


                    if (colisao && (enemy!= enemy_2)){
                        std::cout << "\n\n\n COLIDIIUUUUUUUUUUUuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu \n\n\n" << std::endl;
                        if (myEnemy->getDirection() == Ship::UP) {
                            myEnemy->changeDirection(Ship::DOWN);
                            
                        } else if (myEnemy->getDirection() == Ship::DOWN) {
                            myEnemy->changeDirection(Ship::UP);
                            
                        } else if (myEnemy->getDirection() == Ship::RIGHT) {
                            myEnemy->changeDirection(Ship::LEFT);
                            
                        } else {
                            myEnemy->changeDirection(Ship::RIGHT);
                        }
                    }else{
                            if (myEnemy->getDirection() == Ship::UP) {
                                if (myEnemy->_y - myEnemy->_velocidade > 0) { 
                                    myEnemy->move();
                                }else{
                                    myEnemy->changeDirection(Ship::DOWN);
                                }
                            } else if (myEnemy->getDirection() == Ship::DOWN) {
                                if (myEnemy->_y + myEnemy->_velocidade < 512) { 
                                    myEnemy->move();
                                }else{
                                    myEnemy->changeDirection(Ship::UP);
                                }
                            } else if (myEnemy->getDirection() == Ship::RIGHT) {
                                if (myEnemy->_x + myEnemy->_velocidade < 512) { 
                                    myEnemy->move();
                                }else{
                                    myEnemy->changeDirection(Ship::LEFT);
                                }
                            } else {
                                if (myEnemy->_x - myEnemy->_velocidade > 0) {
                                    myEnemy->move();
                                }else{
                                    myEnemy->changeDirection(Ship::RIGHT);
                                }
                            }

                    }

                    enemy_2++;
                }
            enemy++;
        }
}

void EnemiesHandler::moveEnemies() {
        colisionEnemies();
    }


__END_API