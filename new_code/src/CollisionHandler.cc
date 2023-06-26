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

bool CollisionHandler::checkCollisionBullet(EnemyShip* enemy, std::list<Shot*>* bullets) {
    
}

bool CollisionHandler::checkCollisionBullet(PlayerShip* enemy, std::list<Shot*>* bullets) {

}





__END_API