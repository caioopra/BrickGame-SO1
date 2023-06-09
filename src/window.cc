#include "../include/window.h"
#include "../include/keyboard.h"

bool cima, baixo, direita, esquerda = false;


Window::Window(PlayerShip* player, EnemyShip* enemy1, Keyboard* keyboard) {
    _player_ship = player;
    _first_enemy = enemy1;
    _keyboard = keyboard;

    load_and_bind_textures();
}

void Window::draw_texture(unsigned int texture, int length, int height, float angle)
{
}

void Window::run() {
    sf::RenderWindow window(sf::VideoMode(900, 560), "SFML works!");

    //Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    //https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    window.setKeyRepeatEnabled(false);

    window.setFramerateLimit(10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                 window.close();
                 break;
            
            // key pressed
            case sf::Event::KeyPressed:
                _keyboard->receiveEvent(event);
                

            case sf::Event::KeyReleased:
                _keyboard->receiveEvent(event);
            }
        }

        window.clear();
        window.draw(maze_sprite);

        _player_ship->move();

        _player_ship->getShipSprite()->setPosition(_player_ship->getx(), _player_ship->gety());
        window.draw(*_player_ship->getShipSprite());

        _first_enemy->getShipSprite()->setPosition(245, 150);
        window.draw(*_first_enemy->getShipSprite());

        shot_sprite.setPosition(204, 400);
        window.draw(shot_sprite);
       
        window.display();
    }
}

void Window::load_and_bind_textures() {
    // Bind map textures     
    maze_tex.loadFromFile("sprites/maze/screen.png");
    maze_sprite.setTexture(maze_tex);
    maze_sprite.scale(1.5, 1.5);

    shot_tex.loadFromFile("sprites/space_ships/shot.png");
    shot_sprite.setTexture(shot_tex);
    shot_sprite.scale(-0.5, -0.5);
}
