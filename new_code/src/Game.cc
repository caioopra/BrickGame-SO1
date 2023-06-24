#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "../include/Game.h"


Game::Game() : _keyboard(&_player) {
    this->initWindow();
    initializeVariables();
    // _keyboard = Keyboard(&_player)
}

void Game::initializeVariables() {
}

void Game::initWindow(){
    _window.create(sf::VideoMode(900,560), "Brick Game", sf::Style::Titlebar|sf::Style::Close);
}


Game::~Game() {
    
}


void Game::pollEvents(){
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            case sf::Event::KeyPressed:
                _keyboard.receiveEvent(_event);
                break; 
        }
    }

}

void Game::update(){
    pollEvents();
    render();
    moveAll();
}

void Game::moveAll() {
    _player.move();

}

