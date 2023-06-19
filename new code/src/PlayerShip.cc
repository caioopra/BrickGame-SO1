#include "../include/PlayerShip.h"
#include <iostream>

PlayerShip::PlayerShip() : Ship() {
    _cima.loadFromFile("sprites/space_ships/space_ship1.png");
    _esquerda.loadFromFile("sprites/space_ships/space_ship2.png");
    _baixo.loadFromFile("sprites/space_ships/space_ship3.png");
    _direita.loadFromFile("sprites/space_ships/space_ship4.png");

    _direction = UP;
    _moving = false;
    _ship_sprite.setTexture(_cima);
    _ship_sprite.scale(0.5, 0.5);
}
