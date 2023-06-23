#ifndef Ship_h
#define Ship_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include <list>
#include "Shot.h"

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
    // std::list<Shot>& getShots() {return player_shots;}
    void changeDirection(Direction new_direction);
    
    void setMoving(bool moving);


protected:
    sf::Sprite _ship_sprite;
    sf::Texture _cima, _baixo, _esquerda, _direita;
    Direction _direction;  
      
    bool _moving;
    int _velocidade;

    // std::list <Shot> player_shots;
};

#endif
