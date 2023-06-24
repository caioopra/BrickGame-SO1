#include "../include/Game.h"

#include <cstddef>
#include <cstdlib>
#include <iostream>

Game::Game() : _keyboard(&_player) {
    this->initWindow();
    initializeVariables();
    // _keyboard = Keyboard(&_player)
}

void Game::initializeVariables() {
}

void Game::initWindow() {
    _window.create(sf::VideoMode(900, 560), "Brick Game", sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game() {
}

void Game::run() {
    while (running()) {
        pollEvents();
        update();
    }
}

void Game::pollEvents() {
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

void Game::update() {
    render();
    moveAll();
}

void Game::moveAll() {
    _player.move();
}
