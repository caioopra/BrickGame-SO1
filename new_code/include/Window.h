#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include "threading/traits.h"
#include "Config.h"
#include <list>
#include <iterator>

__BEGIN_API

class Window {
public:
    Window();
    ~Window();

    void run();
    void pause();
    void close();

    void render();

    sf::RenderWindow* getWindow() { return _window; }
private:
    sf::RenderWindow* _window;
    sf::Texture _background_texture;
    sf::Sprite _background_sprite;
    static std::list<sf::Sprite> _spritesToDraw;

    bool closed = false;
    bool paused = false;

};

__END_API

#endif