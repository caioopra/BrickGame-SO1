#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <list>
#include "Shot.h"
#include "threading/thread.h"
#include "threading/traits.h"

__BEGIN_API

class Ship {
public:
    Ship();

    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    sf::Sprite* getShipSprite() { return &_ship_sprite; }
    void setShipSprite(sf::Sprite sprite) { _ship_sprite = sprite; }

    void move();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void createShot();


    int getVelocidade() {return _velocidade; }
    bool getMoving() { return _moving; }
    int getDirection() { return _direction; }
    // std::list<Shot>& getShots() { return _shots; }
    void changeDirection(Direction new_direction);
    
    void setMoving(bool moving);


    std::list<Shot>& _shots;
protected:
    sf::Sprite _ship_sprite;
    sf::Texture _cima, _baixo, _esquerda, _direita;
    Direction _direction;  

    sf::Texture _shot_texture;
    sf::Sprite _shot_sprite;
      
    bool _moving;
    int _velocidade;

    int _x = 200;
    int _y = 200;

};

__END_API

#endif
