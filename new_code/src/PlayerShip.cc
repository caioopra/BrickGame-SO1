#include "../include/PlayerShip.h"

__BEGIN_API

PlayerShip::PlayerShip() : Ship() {
    _cima.loadFromFile("sprites/space_ships/space_ship1.png");
    _esquerda.loadFromFile("sprites/space_ships/space_ship2.png");
    _baixo.loadFromFile("sprites/space_ships/space_ship3.png");
    _direita.loadFromFile("sprites/space_ships/space_ship4.png");

    _direction = UP;
    _moving = false;
    _ship_sprite.setTexture(_cima);
    _ship_sprite.scale(0.5, 0.5);

    _x = 200;
    _y = 200;
}

void PlayerShip::run() {
    // std::cout << "Player running" << std::endl;
    // move();
    _ship_sprite.setPosition(_x,_y);

    // std::list<Shot*>::iterator shotsIterator;
    // for (shotsIterator = _shots->begin(); shotsIterator != _shots->end();shotsIterator++) {
    //     my_shot.move();
    // }
}

__END_API
