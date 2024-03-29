#include "../include/Ship.h"
#include "../include/Shot.h"

__BEGIN_API


Ship::Ship() {
    _shots =  new std::list<Shot*>;
    _velocidade = 5;
    _shot_clock = sf::Clock();
    _movement_clock = sf::Clock();
}

// TODO: deletar tiros da lista
Ship::~Ship() {
    delete _shots;
}

void Ship::move() {
    if (_moving) {
        switch(_direction) {
            case UP:
                moveUp();
                break;
            case DOWN:
                moveDown();
                break;
            case RIGHT:
                moveRight();
                break;
            case LEFT:
                moveLeft();
                break;
        }
    }
}

void Ship::moveUp() {
    _y -= _velocidade;
    _ship_sprite.setTexture(_cima);
}

void Ship::moveDown() {
    _y += _velocidade;
    _ship_sprite.setTexture(_baixo);
}

void Ship::moveRight() {
    _x += _velocidade;
    _ship_sprite.setTexture(_direita);
}

void Ship::moveLeft() {
    _x -= _velocidade;
    _ship_sprite.setTexture(_esquerda);
}

void Ship::changeDirection(Direction new_direction) {
    if (_direction != new_direction)
        _direction = new_direction;
    
    this->setMoving(true);
}


void Ship::setMoving(bool moving) {
    _moving = moving;
}

void Ship::createShot() {
    if (_direction == UP){
        Shot * shot = new Shot(_x+17, _y-17, _direction);
        _shots->push_back(shot);
    } else if (_direction == DOWN){
        Shot * shot = new Shot(_x+17, _y+48, _direction);
        _shots->push_back(shot);
    } else if (_direction == RIGHT){
        Shot* shot = new Shot(_x+48, _y+17, _direction);
        _shots->push_back(shot);
    } else if (_direction == LEFT){
        Shot* shot = new Shot(_x, _y+17, _direction);
        _shots->push_back(shot);
    }
}

bool Ship::canShot(){
    sf::Time newTime = _shot_clock.getElapsedTime();
    if (newTime.asMilliseconds()>500){
        _shot_clock.restart();
        return true;
    }else{
        return false;
    }
}

bool Ship::canMove(){
    sf::Time newTime = _movement_clock.getElapsedTime();
    if (newTime.asMilliseconds()>25) {
        _movement_clock.restart();
        return true;
    } else {
        return false;
    }
}


__END_API