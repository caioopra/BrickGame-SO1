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
    _font.loadFromFile("sprites/font.ttf");

    _score_text.setFont(_font);
    _score_text.setString("Score: " + std::to_string(_gameHandler->_score));
    _score_text.setCharacterSize(30);
    _score_text.move(580, 45);

    _speed_text.setFont(_font);
    _speed_text.setString("Velocidade: " + std::to_string(_gameHandler->_speed));
    _speed_text.setCharacterSize(27);
    _speed_text.move(580, 85);
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

    for (auto enemy : *_gameHandler->_enemies) {
        _window.draw(*enemy->getShipSprite());

        for (auto shot : *enemy->_shots) {
            _window.draw(shot->getShotSprite());
        }
    }

    for (auto shot : *_gameHandler->_player->_shots) {
        shot->move();
        _window.draw(shot->getShotSprite());
    }
    
    _window.draw(_score_text);
    _window.draw(_speed_text);

    _window.display();
    std::cout<< " WINDOW DISPLAY" << std::endl;    
}
__END_API