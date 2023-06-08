#ifndef window_h
#define window_h

#include <iostream>
#include <png.h>
#include <SFML/Graphics.hpp>

#include "PlayerShip.h"
#include "EnemyShip.h"

class Window {
public:
    Window(PlayerShip* player, EnemyShip* enemy1);

    void run();

    void draw_texture(unsigned int texture, int length, int height, float angle);

    bool checkCollision(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2);

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

    //Enemy space ship texture
    sf::Texture enemy_ship_tex;
    sf::Sprite enemy_ship_sprite;
};

#endif
