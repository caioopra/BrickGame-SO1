#include "../include/PlayerShip.h"
#include <iostream>
#include "../include/Config.h"
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
    _ship_sprite.setPosition(200,200);
    _gameHandler->_toDrawSprites->push_back(_ship_sprite);
}

void PlayerShip::run() {
    while(!Config::isGameOver){
    std::cout << "RUNNING: PLAYER SHIP" << std::endl;
    std::cout << "END: PLAYER SHIP" << std::endl;
    Thread::yield();
    }
}

__END_API
