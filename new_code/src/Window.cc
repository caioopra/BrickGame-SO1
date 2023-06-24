#include "../include/Window.h"
#include "../include/Config.h"
__BEGIN_API

Window::Window() {
    _background_texture.loadFromFile("../sprites/maze/screen.png");
    _background_sprite.setTexture(_background_texture);
    _background_sprite.scale(1.5, 1.5);
}

void Window::run() {
    sf::RenderWindow window(sf::VideoMode(Config::width,Config::height), "Brick Game", sf::Style::Titlebar|sf::Style::Close);
    this->_window = &window;
    _window->setKeyRepeatEnabled(true);
    _window->setFramerateLimit(60);

    while(_window->isOpen()){
        _window->clear();

        std::list<sf::Sprite>::iterator drawableIterator;
        std::list<sf::Sprite>& drawables = _spritesToDraw;
        _window->draw(_background_sprite);
        for (drawableIterator = drawables.begin(); drawableIterator != drawables.end(); drawableIterator++){
            _window->draw(*drawableIterator);
        }
    }
}

__END_API