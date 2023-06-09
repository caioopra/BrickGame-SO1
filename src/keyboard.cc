#include "../include/keyboard.h"
#include <SFML/Window/Keyboard.hpp>

Keyboard::Keyboard(PlayerShip* player) {
    _player = player;
}

void Keyboard::receiveEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _player->changeDirection(Ship::LEFT);
            std::cout << "KEYBOARD left" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _player->changeDirection(Ship::RIGHT);
            std::cout << "KEYBOARD right" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _player->changeDirection(Ship::UP);
            std::cout << "KEYBOARD up" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _player->changeDirection(Ship::DOWN);
            std::cout << "KEYBOARD down" << std::endl;
        } else {
            std::cout << "KEYBOARD tecla " <<event.key.code << std::endl;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if(event.key.code  == sf::Keyboard::Left) {
            std::cout << "KEYBOARD esquerda solto!" << std::endl; 
            _player->setMoving(false);
        } else if(event.key.code  == sf::Keyboard::Right) {
            std::cout << "KEYBOARD direita solto!" << std::endl;
            _player->setMoving(false);
        } else if(event.key.code == sf::Keyboard::Down) { 
            std::cout << "KEYBOARD para baixo solto!" << std::endl; 
            _player->setMoving(false);
        } else if(event.key.code == sf::Keyboard::Up) { 
            std::cout << "KEYBOARD para cima solto!" << std::endl; 
            _player->setMoving(false);
        } else { 
            std::cout << "KEYBOARD pressed = " << event.key.code << std::endl; 
        }
    }
}
