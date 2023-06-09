#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>

#include "PlayerShip.h"
#include "EnemyShip.h"
#include "keyboard.h"

class Window {
public:
    Window(PlayerShip* player, EnemyShip* enemy1, Keyboard* keyboard);

    void run();

    void draw_texture(unsigned int texture, int length, int height, float angle);

private:
    void load_and_bind_textures();


private:
    // Maze Texture
    sf::Texture maze_tex;
    sf::Sprite maze_sprite;
    
    //Shot texture
    sf::Texture shot_tex;
    sf::Sprite shot_sprite;
    
    //Space ship texture
    PlayerShip* _player_ship;

    EnemyShip* _enemies_list[4];
    EnemyShip* _first_enemy;
    Keyboard* _keyboard;

    //Enemy space ship texture
    sf::Texture enemy_ship_tex;
    sf::Sprite enemy_ship_sprite;
};

#endif
