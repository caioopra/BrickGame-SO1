#ifndef Ship_h
#define Ship_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>


class Ship {
public:
    Ship();
    ~Ship();

    sf::Sprite getShipSprite() { return _ship_sprite; }
    void setShipSprite(sf::Sprite sprite) { _ship_sprite = sprite; }

protected:
    sf::Texture _ship_texture;
    sf::Sprite _ship_sprite;

    sf::Texture _shot_texture;
    sf::Sprite _shot_sprite;
};

#endif
