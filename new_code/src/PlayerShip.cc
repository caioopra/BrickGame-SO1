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

}

void PlayerShip::run() {
    std::cout << "Player running\n\n" << std::endl;
    move();
    _ship_sprite.setPosition(_x, _y);
    // _ship_sprite.setPosition(_x,_y);
    // _gameHandler->_toDrawSprites->push_back(_ship_sprite);

}

__END_API
