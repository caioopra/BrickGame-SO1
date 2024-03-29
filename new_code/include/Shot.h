#ifndef Shot_h
#define Shot_h

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API

class Shot {
   public:
    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };
    Shot(int x, int y, int direction);

    sf::Sprite getShotSprite() { return _shot_sprite; }
    void setShotSprite(sf::Sprite sprite) { _shot_sprite = sprite; }

    void move();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    bool canMove();

    int getVelocidade() { return _velocidade; }
    int getDirection() { return _direction; }
    void changeDirection(Direction new_direction);

    int _x, _y;
    sf::Texture _shot_texture;
    sf::Sprite _shot_sprite;

    int _direction;

    int _velocidade;

    sf::Clock _clock;
   protected:
};

__END_API
#endif
