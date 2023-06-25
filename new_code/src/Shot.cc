#include "../include/Shot.h"

__BEGIN_API

Shot::Shot(int x, int y, int direction) {
    _shot_texture.loadFromFile("sprites/space_ships/shot.png");
    _shot_sprite.setTexture(_shot_texture);
    _shot_sprite.scale(0.5, 0.5);

    _velocidade = 20;
    _direction = direction;

    _shot_sprite.setPosition(x,y);
    _x = x;
    _y = y;
}

void Shot::move() {
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

void Shot::moveUp() { 
    _y -= _velocidade;
}

void Shot::moveDown() {
    _y += _velocidade;
}

void Shot::moveRight() {
    _x += _velocidade;
}

void Shot::moveLeft() {
    _x -= _velocidade;
}


__END_API
