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
    sf::Texture ship;
    sf::Texture shot;
    sf::Sprite ship_sprite;
    sf::Sprite shot_sprite;
    sf::Sprite shot2_sprite;
    
    ship.loadFromFile("sprites/space_ships/space_ship1.png");
    shot.loadFromFile("sprites/space_ships/shot.png");

    ship_sprite.setTexture(ship);
    shot_sprite.setTexture(shot);
    shot_sprite.setPosition(50,40);
    ship_sprite.setPosition(200,200);
    shot2_sprite.setTexture(shot);
    shot2_sprite.setPosition(400,400);

    _spritesToDraw.push_back(shot_sprite);
    _spritesToDraw.push_back(ship_sprite);
    _spritesToDraw.push_back(shot2_sprite);

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
    for (drawableIterator = _spritesToDraw.begin(); drawableIterator != _spritesToDraw.end(); drawableIterator++) {
        sf::Sprite my_sprite = *drawableIterator;
        _window.draw(my_sprite);
        
    }        

    _window.display();
    
}
__END_API