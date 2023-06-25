#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>

class Keyboard {
public:
    Keyboard(); 

    void receiveEvent(sf::Event event);
    bool can_shot;
private:
    PlayerShip* _player;
};


#endif
