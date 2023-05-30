#ifndef Ship_h
#define Ship_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>


class Ship {
public:
    Ship();
    ~Ship();

private:
    sf::Texture ship_texture;
    sf::Sprite ship_sprite;

    sf::Texture shot_texture;
    sf::Sprite shot_sprite;
};

#endif
