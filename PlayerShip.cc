#include "PlayerShip.h"
#include <iostream>

PlayerShip::PlayerShip(int id) : Ship() {
    _ship_texture.loadFromFile("sprites/space_ships/space_ship1.png");
    _ship_sprite.setTexture(_ship_texture);
    id = id;
}
