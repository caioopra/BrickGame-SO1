#include "../include/EnemyShip.h"
#include <iostream>

__BEGIN_API

EnemyShip::EnemyShip(int movement, int x, int y) : Ship() {
    _cima.loadFromFile("sprites/space_ships/enemy_space_ship1.png");
    _esquerda.loadFromFile("sprites/space_ships/enemy_space_ship2.png");
    _baixo.loadFromFile("sprites/space_ships/enemy_space_ship3.png");
    _direita.loadFromFile("sprites/space_ships/enemy_space_ship4.png");

    _direction = UP;
    _ship_sprite.setTexture(_cima);
    _ship_sprite.scale(0.5, 0.5);
    _movement_algorithm = movement;
    initial_x = x;
    initial_y = y;
    _x = x;
    _y = y;

    _ship_sprite.setPosition(x, y);
    _revive_clock = sf::Clock();
}

void EnemyShip::run() {
    while (!Config::isGameOver) {
        // if(canMove()){
        //     move();
        // }
        Thread::yield();
    }
}

__END_API
