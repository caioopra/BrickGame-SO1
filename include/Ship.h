#ifndef Ship_h
#define Ship_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>

class Ship {
public:
    Ship();

    sf::Sprite* getShipSprite() { return &_ship_sprite; }
    void setShipSprite(sf::Sprite sprite) { _ship_sprite = sprite; }

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    int getx() { return _x; }
    int gety() {return _y;}


protected:
    sf::Texture _ship_texture;
    sf::Sprite _ship_sprite;

    sf::Texture _shot_texture;
    sf::Sprite _shot_sprite;

    sf::Texture _cima, _baixo, _esquerda, _direita;
    
    int _velocidade;

    int _x, _y;
    int _speed;
};

#endif
