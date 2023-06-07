#include "../include/Ship.h"

Ship::Ship() {
    _shot_texture.loadFromFile("sprites/space_ships/shot.png");
    _shot_sprite.setTexture(_shot_texture);
    _velocidade = 1;
}

void Ship::moveUp() {
    _y += _velocidade;
    _ship_sprite.setTexture(_cima);
}

void Ship::moveDown() {
    _y -= _velocidade;
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