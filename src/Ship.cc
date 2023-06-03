#include "../include/Ship.h"

Ship::Ship() {
    _shot_texture.loadFromFile("sprites/space_ships/shot.png");
    _shot_sprite.setTexture(_shot_texture);
}

