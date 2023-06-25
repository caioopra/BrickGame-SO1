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
            std::cout << event.type << "\n\n\n" << std::endl;
            switch (event.type) {
                case sf::Event::Closed:
                    _window.close();
                    break;

                case sf::Event::KeyPressed:
                    std::cout << "djbawygbfiuwahuifbweuanbgib uifbaibnfuilanh wawhuihaqwjnaflnakfnawjkuyfgag e" << std::endl;
                    _gameHandler->_eventList->push_back(event);
                    
                case sf::Event::KeyReleased:
                    _gameHandler->_eventList->push_back(event);
                

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

    std::list<Shot>::iterator shotsIterator;
    std::cout<< "AQUIIIIIII\n\n\n" << _gameHandler->_player->_shots.size()<< "\n\n\n\\n"<< std::endl;
    for (shotsIterator = _gameHandler->_player->_shots.begin(); shotsIterator != _gameHandler->_player->_shots.end();shotsIterator++) {
        Shot my_shot = *shotsIterator;
        _window.draw(my_shot.getShotSprite());
        std::cout<< " WINDOW DRAW SHOT" << std::endl;
    }
    
    // for (drawableIterator = sprites.begin(); drawableIterator != sprites.end();drawableIterator++) {
    //     sf::Sprite my_sprite = *drawableIterator;
    //     // _window.draw(my_sprite);
    //     std::cout<< " WINDOW DRAW" << std::endl;
    // }
    // for (drawableIterator = sprites.begin(); drawableIterator != sprites.end();drawableIterator++) {
    //     sf::Sprite my_sprite = *drawableIterator;
    //     // _window.draw(my_sprite);
    //     std::cout<< " WINDOW DRAW" << std::endl;
    // }

    _window.display();
    std::cout<< " WINDOW DISPLAY" << std::endl;
    
}
__END_API