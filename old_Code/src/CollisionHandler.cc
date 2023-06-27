#include "../include/CollisionHandler.h"

CollisionHandler::CollisionHandler(PlayerShip* player, EnemyShip* enemy) {
    _player = player;
    _enemy = enemy;
}

int CollisionHandler::getFuturePosition() {
    if (_player->getDirection() == Ship::UP) {
        return _player->gety() - _player->getVelocidade();
    } else if (_player->getDirection() == Ship::DOWN) {
        return _player->gety() + _player->getVelocidade();
    } else if (_player->getDirection() == Ship::RIGHT) {
        return _player->getx() + _player->getVelocidade();
    } else {
        return _player->getx() - _player->getVelocidade();
    }
}

bool CollisionHandler::checkIfWillCollide(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2) {
    bool colisao_1 = ((y1 > y2) && (y1 < y2 + height2)) || ((y1 + height1 > y2) && (y1 + height1 < y2 + height2));
    bool colisao_2 = ((x1 > x2) && (x1 < x2 + width2)) || ((x1 + width1 > x2) && (x1 + width1 < x2 + width2));

    bool colisao = colisao_1 && colisao_2;

    if (colisao) {
        return true;
    }
    return false;
}

bool CollisionHandler::checkCollision(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2) {
    int future_position = getFuturePosition();
    bool collision;

    if (_player->getDirection() == Ship::RIGHT) {
        collision = checkIfWillCollide(future_position, y1, x2, y2, width1, height1, width2, height2);
        if (collision) 
            return true;
        
        if (_player->getx() < 510)
            
            _player->move();

    } else if (_player->getDirection() == Ship::LEFT) {
        collision = checkIfWillCollide(future_position, y1, x2, y2, width1, height1, width2, height2);
        if (collision)
            return true;

        if (_player->getx() > 24)
            _player->move();
    } else if (_player->getDirection() == Ship::UP) {
        collision = checkIfWillCollide(x1, future_position, x2, y2, width1, height1, width2, height2);
        if (collision)
            return true;

        if (_player->gety() > 24)
            _player->move();
    } else {
        collision = checkIfWillCollide(x1, future_position, x2, y2, width1, height1, width2, height2);
        if (collision)
            return true;

        if (_player->gety() < 510)
            _player->move();
    }

    return false;
}

bool CollisionHandler::check(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2) {
    bool colisao_1 = ((y1 > y2) && (y1 < y2 + height2)) || ((y1 + height1 > y2) && (y1 + height1 < y2 + height2));
    bool colisao_2 = ((x1 > x2) && (x1 < x2 + width2)) || ((x1 + width1 > x2) && (x1 + width1 < x2 + width2));

    bool colisao = colisao_1 && colisao_2;

    return colisao;
}
