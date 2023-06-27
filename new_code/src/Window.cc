#include "../include/Window.h"

#include <iostream>
#include <list>

#include "../include/Config.h"
__BEGIN_API

Window::Window() {
    _window.create(sf::VideoMode(Config::width, Config::height), "Brick Game", sf::Style::Titlebar | sf::Style::Close);
    _window.setKeyRepeatEnabled(true);
    // _window.setFramerateLimit(60);
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

    _lives_text.setFont(_font);
    _lives_text.setString("N. vidas: 3");
    _lives_text.setCharacterSize(27);
    _lives_text.move(580, 125);
}

void Window::run() {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _window.close();
                    break;
                case sf::Event::KeyPressed:
                    _gameHandler->_eventList->push_back(event);
                    if (event.key.code == sf::Keyboard::P) {
                        std::cout << "GAME BEING PAUSED " << std::endl;
                        if (_paused) {
                            _gameHandler->unpause();
                        } else {
                            _gameHandler->pause();
                            drawPauseScreen();
                        }
                        _paused = !_paused;                
                    } else if (event.key.code == sf::Keyboard::Q){
                        _window.close();
                        break;
                    } else if (event.key.code == sf::Keyboard::R && _gameHandler->_player->vidas == 0) {
                        _gameHandler->reset();
                        _gameHandler->unpause();
                        break;
                    }
                case sf::Event::KeyReleased:
                    _gameHandler->_eventList->push_back(event);
                    break;
            }
        }

        if(_gameHandler->_player->vidas == 0 && !_gameHandler->_is_over){
            std::cout << "ENDING GAME" << std::endl;
            drawEndScreen();
            _window.display();  
            _gameHandler->pause();
            _gameHandler->_is_over=true;
            Config::isGameOver = false;
        }

        if (!_paused) {
            update();
        }
        _window.display();


        // std::cout<< " WINDOW LOOP" << std::endl;
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
        _window.draw(shot->getShotSprite());
    }

    _score_text.setString("Score: " + std::to_string(_gameHandler->_score));
    _speed_text.setString("Velocidade: " + std::to_string(_gameHandler->_speed));

    _window.draw(_score_text);
    _window.draw(_speed_text);
    _window.draw(_lives_text);

    // _window.display();
    // std::cout<< " WINDOW DISPLAY" << std::endl;
}

void Window::drawPauseScreen() {
    std::cout << "DRAWING PAUSE SCREEN " << std::endl;
    sf::Text text;
    text.setFont(_font);
    text.setString("GAME PAUSED! PRESS P TO RESUME");
    text.setCharacterSize(40);
    text.move(30, 240);
    _window.draw(text);
}

void Window::drawEndScreen() {
    std::cout << "DRAWING END SCREEN" << std::endl;
    sf::Text text;
    text.setFont(_font);
    text.setString("GAME OVER!");
    text.setCharacterSize(40);
    text.move(200, 240);
    _window.draw(text);

}

__END_API