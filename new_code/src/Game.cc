#include "../include/Game.h"
#include <iostream>

__BEGIN_API

Game::Game() : _keyboard(&_player) {
    std::cout << "Game instanciated" << std::endl;
}

void Game::run() {
    _window.run();
}

// void Game::pollEvents() {
//     while (_window.getWindow()->pollEvent(_event)) {
//         switch (_event.type) {
//             case sf::Event::Closed:
//                 _window.getWindow()->close();
//                 break;
//             case sf::Event::KeyPressed:
//                 _keyboard.receiveEvent(_event);
//                 break;
//         }
//     }
// }

// void Game::update() {
//     render();
//     moveAll();
// }

// void Game::moveAll() {
//     _player.move();
// }

// void Game::render() {
//     std::cout << "asdasdas" << std::endl;
// }


__END_API
