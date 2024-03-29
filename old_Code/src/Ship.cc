#include "../include/Ship.h"
#include "../include/Shot.h"

Ship::Ship() {
    _shot_texture.loadFromFile("sprites/space_ships/shot.png");
    _shot_sprite.setTexture(_shot_texture);
    _velocidade = 20;
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

void Ship::createShot(){
    if (_direction == UP){
        player_shots.push_back(Shot(_x+31, _y, _direction));
    } else if (_direction == DOWN){
        player_shots.push_back(Shot(_x+31, _y+48, _direction));
    }else if (_direction == RIGHT){
        player_shots.push_back(Shot(_x+48, _y+31, _direction));
    }else if (_direction == LEFT){
        player_shots.push_back(Shot(_x, _y+31, _direction));
    }
}