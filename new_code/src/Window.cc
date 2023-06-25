#include "../include/Window.h"
#include "../include/Config.h"
#include <list>
#include <iostream>
__BEGIN_API

std::list<sf::Sprite> Window::_spritesToDraw;

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
        update();
    }
}

void Window::update() {
    _window.clear();

    _window.draw(_background_sprite);
    


    std::list<sf::Sprite>::iterator drawableIterator;
    std::list<sf::Sprite> drawables = _spritesToDraw;
    _window.draw(_background_sprite);
    for (drawableIterator = drawables.begin(); drawableIterator != drawables.end(); drawableIterator++) {
        _window.draw(*drawableIterator);
    }        


    _window.display();
    
}
__END_API