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
    _positions[0] = 150;
    _positions[1] = 150;

    _positions[2] = 20;
    _positions[3] = 20;

    _positions[4] = 300;
    _positions[5] = 20;

    _positions[6] = -1;
    _positions[7] = 500;

    _positions[8] = 300;
    _positions[9] = 500;
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
    
    if (_positions[2] >= 0) {
        _enemy1.move();
    }
    if (_positions[4] >= 0) {
        _enemy2.move();
    }
    if (_positions[6] >= 0) {    
        _enemy3.move();
    }
    if (_positions[8] >= 0) {
        _enemy4.move();
    }
}

void Game::render() {
    _window.clear();

    _player.getShipSprite()->setPosition(_positions[0], _positions[1]);
    _window.draw(*_player.getShipSprite());
    
    if (_positions[2] >= 0) {
        _enemy1.getShipSprite()->setPosition(_positions[2], _positions[3]);
        _window.draw(*_enemy1.getShipSprite());
    }
    if (_positions[4] >= 0) {
        _enemy2.getShipSprite()->setPosition(_positions[4], _positions[5]);
        _window.draw(*_enemy2.getShipSprite());
    }
    if (_positions[6] >= 0) {    
        _enemy3.getShipSprite()->setPosition(_positions[6], _positions[7]);
        _window.draw(*_enemy3.getShipSprite());
    }
    if (_positions[8] >= 0) {
        _enemy4.getShipSprite()->setPosition(_positions[8], _positions[9]);
        _window.draw(*_enemy4.getShipSprite());
    }

    _window.display();
}