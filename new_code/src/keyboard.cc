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
        std::cout << "RUNNING: KEYBOARD" << std::endl;

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
            // std::cout << "KEYBOARD left" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _gameHandler->_player->changeDirection(Ship::RIGHT);
            // std::cout << "KEYBOARD right" << std::endl;
        } 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _gameHandler->_player->changeDirection(Ship::UP);
            // std::cout << "KEYBOARD up" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _gameHandler->_player->changeDirection(Ship::DOWN);
            // std::cout << "KEYBOARD down" << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            // std::cout << "KEYBOARD atirando" << std::endl;
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
            // std::cout << "KEYBOARD esquerda solto!" << std::endl; 
            
            _gameHandler->_player->setMoving(false);
        } else if(event.key.code  == sf::Keyboard::Right) {
            // std::cout << "KEYBOARD direita solto!" << std::endl;
            _gameHandler->_player->setMoving(false);
        }
        if(event.key.code == sf::Keyboard::Down) { 
            // std::cout << "KEYBOARD para baixo solto!" << std::endl; 
            _gameHandler->_player->setMoving(false);
        } else if(event.key.code == sf::Keyboard::Up) { 
            // std::cout << "KEYBOARD para cima solto!" << std::endl; 
            _gameHandler->_player->setMoving(false);
        }
        if(event.key.code == sf::Keyboard::Space){
            // std::cout << "KEYBOARD espaco solto!" << std::endl; 
            can_shot = true;
        } 
        
        // else { 
        //     std::cout << "KEYBOARD pressed = " << event.key.code << std::endl; 
        // }
    }
}

__END_API