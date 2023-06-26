#include "../include/CollisionHandler.h"
#include "../include/Config.h"

__BEGIN_API

CollisionHandler::CollisionHandler() {
    std::cout << "COLLISION HANDLER INSTANTIATED" << std::endl;
}

void CollisionHandler::run() {
    while(!Config::isGameOver){
        checkBorderCollision();
        checkBorderCollisionShot();
        checkBorderCollisionEnemyShot();
        checkCollisionBulletEnemy();
        checkCollisionBulletPlayer();


        std::cout << "COLLISION HANDLER - CHECKING FOR COLLISION" << std::endl;
        Thread::yield();
    }
}

void CollisionHandler::checkBorderCollision() {
    if (_gameHandler->_player->getDirection() == Ship::UP) {
        if (_gameHandler->_player->_y - _gameHandler->_player->_velocidade > 0) { 
            _gameHandler->_player->move();
        }
    } else if (_gameHandler->_player->getDirection() == Ship::DOWN) {
        if (_gameHandler->_player->_y + _gameHandler->_player->_velocidade < 512) { 
            _gameHandler->_player->move();
        }
    } else if (_gameHandler->_player->getDirection() == Ship::RIGHT) {
        if (_gameHandler->_player->_x + _gameHandler->_player->_velocidade < 512) { 
            _gameHandler->_player->move();
        }
    } else {
        if (_gameHandler->_player->_x - _gameHandler->_player->_velocidade > 0) {
            _gameHandler->_player->move();
        }
    }
}

void CollisionHandler::checkBorderCollisionShot() {
    std::list<Shot*>::iterator it;

    for (it = _gameHandler->_player->_shots->begin(); it != _gameHandler->_player->_shots->end();) {
        Shot* shot = *it;
        if (shot->getDirection() == Shot::UP) {
            if (shot->_y - shot->_velocidade > 0) { 
                shot->move();
            } else {
                it = _gameHandler->_player->_shots->erase(it);
            }
        } else if (shot->getDirection() == Shot::DOWN) {
            if (shot->_y + shot->_velocidade < 512) { 
                shot->move();
            } else {
                it = _gameHandler->_player->_shots->erase(it);
            }
        } else if (shot->getDirection() == Shot::RIGHT) {
            if (shot->_x + shot->_velocidade < 512) { 
                shot->move();
            } else {
                it = _gameHandler->_player->_shots->erase(it);
            }
        } else {
            if (shot->_x - shot->_velocidade > 0) {
                shot->move();
            } else {
                it = _gameHandler->_player->_shots->erase(it);
            }
        }

        it++;
        
    }
}

void CollisionHandler::checkCollisionBulletEnemy() {
    std::list<Shot*>::iterator playerShot;
    for (playerShot = _gameHandler->_player->_shots->begin(); playerShot != _gameHandler->_player->_shots->end();) {
        Shot* shot = *playerShot;
        std::list<EnemyShip*>::iterator enemy;
        for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
            EnemyShip* myEnemy= *enemy;
            if (shot->_shot_sprite.getGlobalBounds().intersects(myEnemy->getShipSprite()->getGlobalBounds())) {
                playerShot = _gameHandler->_player->_shots->erase(playerShot);
                enemy = _gameHandler->_enemies->erase(enemy);
                std::cout << "COLISÃO ENTRE INIMIGO E BALA" << std::endl;
            }
            enemy++;
        }   
        playerShot++;
    }
}

void CollisionHandler::checkCollisionBulletPlayer(){
    std::list<EnemyShip*>::iterator enemy;
    for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
        EnemyShip* myEnemy= *enemy;
        std::list<Shot*>::iterator enemyShot;
        for (enemyShot = myEnemy->_shots->begin(); enemyShot != myEnemy->_shots->end();) {
            Shot* shot = *enemyShot;
            if (shot->_shot_sprite.getGlobalBounds().intersects(_gameHandler->_player->getShipSprite()->getGlobalBounds())) {
                enemyShot = myEnemy->_shots->erase(enemyShot);

                //TODO: ADICIONAR LOGICA DE PERDER VIDA
        }
        enemyShot++;
    }
    enemy++;
    }
}

void CollisionHandler::checkBorderCollisionEnemyShot() {
    std::list<EnemyShip*>::iterator enemy;
    for (enemy = _gameHandler->_enemies->begin(); enemy !=_gameHandler->_enemies->end();) {
        EnemyShip* myEnemy= *enemy;
        std::list<Shot*>::iterator enemyShot;
        for (enemyShot = myEnemy->_shots->begin(); enemyShot != myEnemy->_shots->end();) {
            Shot* shot = *enemyShot;
            
            if (shot->getDirection() == Shot::UP) {
                if (shot->_y - shot->_velocidade > 0) { 
                    shot->move();
                } else {
                    enemyShot = myEnemy->_shots->erase(enemyShot);
                }
            } else if (shot->getDirection() == Shot::DOWN) {
                if (shot->_y + shot->_velocidade < 512) { 
                    shot->move();
                } else {
                    enemyShot = myEnemy->_shots->erase(enemyShot);
                }
            } else if (shot->getDirection() == Shot::RIGHT) {
                if (shot->_x + shot->_velocidade < 512) { 
                    shot->move();
                } else {
                    enemyShot = myEnemy->_shots->erase(enemyShot);
                }
            } else {
                if (shot->_x - shot->_velocidade > 0) {
                    shot->move();
                } else {
                    enemyShot = myEnemy->_shots->erase(enemyShot);
                }
            }
            enemyShot++;
        }
        enemy++;
    }
}




__END_API