#include "../include/Keyboard.h"
#include <SFML/Window/Keyboard.hpp>
#include "../include/Config.h"
#include "../include/TimeHandler.h"
__BEGIN_API

TimeHandler timeHandler = TimeHandler();

Keyboard::Keyboard() {

}

void Keyboard::run() {
    while(!Config::isGameOver){
        // std::cout << "RUNNING: KEYBOARD" << std::endl;

        std::list<sf::Event>::iterator eventIterator;

        for (eventIterator = _gameHandler->_eventList->begin(); eventIterator != _gameHandler->_eventList->end();eventIterator++) {
            sf::Event event = *eventIterator;
            receiveEvent(event);
            // std::cout<< " RECEBEU EVENTO" << std::endl;
        }
        Thread::yield();
    } 
}

void Keyboard::receiveEvent(sf::Event event) {
    
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _gameHandler->_player->changeDirection(Ship::LEFT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _gameHandler->_player->changeDirection(Ship::RIGHT);
        } 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _gameHandler->_player->changeDirection(Ship::UP);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _gameHandler->_player->changeDirection(Ship::DOWN);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if (timeHandler.playerCanShot()){
                _gameHandler->_player->createShot();
                can_shot = false;
            }
        }
        // }else {
        //     std::cout << "KEYBOARD tecla " <<event.key.code << std::endl;
        // }
    } else if (event.type == sf::Event::KeyReleased) {
        if(event.key.code  == sf::Keyboard::Left) {            
            _gameHandler->_player->setMoving(false);
        } else if(event.key.code  == sf::Keyboard::Right) {
            _gameHandler->_player->setMoving(false);
        }
        if(event.key.code == sf::Keyboard::Down) { 
            _gameHandler->_player->setMoving(false);
        } else if(event.key.code == sf::Keyboard::Up) { 
            _gameHandler->_player->setMoving(false);
        }
        if(event.key.code == sf::Keyboard::Space){
            can_shot = true;
        } 
        
        // else { 
        //     std::cout << "KEYBOARD pressed = " << event.key.code << std::endl; 
        // }
    }
}

__END_API