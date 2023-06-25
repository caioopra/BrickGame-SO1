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
        update();
        std::cout<< " WINDOW LOOP" << std::endl;
        Thread::yield();
    }
}

void Window::update() {

    _window.clear();

    _window.draw(_background_sprite);

    std::list<sf::Sprite>::iterator drawableIterator;
    std::list<sf::Sprite> sprites = * getGameHandler()->_toDrawSprites;
    std::cout<< sprites.size() <<std::endl;

    for (drawableIterator = sprites.begin(); drawableIterator != sprites.end();drawableIterator++) {
        sf::Sprite my_sprite = *drawableIterator;
        _window.draw(my_sprite);
        std::cout<< " WINDOW DRAW" << std::endl;
    }        
    _window.display();
    std::cout<< " WINDOW DISPLAY" << std::endl;
    
}
__END_API