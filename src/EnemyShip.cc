#include "../include/EnemyShip.h"
#include <iostream>

EnemyShip::EnemyShip(int param_id) : Ship() {
    _ship_texture.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    _ship_sprite.setTexture(_ship_texture);
    _ship_sprite.scale(-0.5, -0.5);
    id = param_id;
}
