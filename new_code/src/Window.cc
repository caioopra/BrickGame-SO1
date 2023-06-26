#include "../include/Window.h"
#include "../include/Config.h"
#include <list>
#include <iostream>
__BEGIN_API

Window::Window() {   
    _window.create(sf::VideoMode(Config::width,Config::height), "Brick Game", sf::Style::Titlebar|sf::Style::Close);
    _window.setKeyRepeatEnabled(true);
    _window.setFramerateLimit(60);
    load_and_bind_textures();
}

void Window::load_and_bind_textures() {
    // Bind map textures 
    _background_texture.loadFromFile("sprites/maze/screen.png");
    _background_sprite.setTexture(_background_texture);
    _background_sprite.scale(1.5, 1.5);
}

void Window::run() {    
    while(_window.isOpen()){
        sf::Event event;
        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _window.close();
                    break;

                case sf::Event::KeyPressed:
                    _gameHandler->_eventList->push_back(event);
                    break;
                case sf::Event::KeyReleased:
                    _gameHandler->_eventList->push_back(event);
                    break;

            }
        }
        update();

        std::cout<< " WINDOW LOOP" << std::endl;
        Thread::yield();
    }
}

void Window::update() {

    _window.clear();

    _window.draw(_background_sprite);

    _window.draw(_gameHandler->_player->_ship_sprite);

    for (auto shot : *_gameHandler->_player->_shots) {
        shot->move();
        _window.draw(shot->getShotSprite());
    }

    _window.display();
    std::cout<< " WINDOW DISPLAY" << std::endl;
    
}
__END_API