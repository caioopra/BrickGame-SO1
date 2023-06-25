#ifndef WINDOW_H
#define WINDOW_H

#include <png.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iterator>
#include <list>

#include "Config.h"
#include "threading/traits.h"

__BEGIN_API

class Window {
   public:
    Window();


    void run();
    void pause();
    void close();
    void load_and_bind_textures();
    void render();
    void update();

    bool getClosed() { return _closed; }

   private:
    sf::RenderWindow _window;
    sf::Texture _background_texture;
    sf::Sprite _background_sprite;
    static std::list<sf::Sprite> _spritesToDraw;

    bool _closed = false;
    bool _paused = false;
};

__END_API

#endif