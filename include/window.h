#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "keyboard.h"
#include "CollisionHandler.h"

class Window {
public:
    Window(Game* game);

    void run();

    void update();

    void draw_texture(unsigned int texture, int length, int height, float angle);

    bool checkCollision(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2);

private:
    void load_and_bind_textures();


private:
    sf::RenderWindow _window;

    // Maze Texture
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;
    
    //Shot texture
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;
    
    Game* _game;
    PlayerShip* _player_ship;

    //Enemy space ship texture
    sf::Texture enemy_ship_tex;
    sf::Sprite enemy_ship_sprite;
};

#endif
