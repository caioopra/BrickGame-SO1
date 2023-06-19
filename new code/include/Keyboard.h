#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include "PlayerShip.h"

class Keyboard {
public:
    Keyboard(PlayerShip* player);  

    void receiveEvent(sf::Event event);
    bool can_shot;
private:
    PlayerShip* _player;
};


#endif
