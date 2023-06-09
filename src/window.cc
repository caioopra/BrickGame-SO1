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

       int x1, x2, y1, y2, width1, height1, width2, height2;
       x1 = _player_ship->getShipSprite()->getGlobalBounds().left;
       y1 = _player_ship->getShipSprite()->getGlobalBounds().top;
       width1 = _player_ship->getShipSprite()->getGlobalBounds().width;
       height1 = _player_ship->getShipSprite()->getGlobalBounds().height;
       x2 = _first_enemy->getShipSprite()->getGlobalBounds().left;
       y2 = _first_enemy->getShipSprite()->getGlobalBounds().top;
       width2 = _first_enemy->getShipSprite()->getGlobalBounds().width;
       height2 = _first_enemy->getShipSprite()->getGlobalBounds().height;


        if (direita){
            int next_X = _player_ship->getx() + _player_ship->getVelocidade();
            bool colision = checkCollision(next_X, y1, x2, y2, width1, height1, width2, height2);
            if (_player_ship->getx() < 510 && !colision){
            _player_ship->moveRight();
            }
        }
        if (esquerda){
            int next_X = _player_ship->getx() - _player_ship->getVelocidade();
            bool colision = checkCollision(next_X, y1, x2, y2, width1, height1, width2, height2);
            if (_player_ship->getx() > 24 && !colision){
                _player_ship->moveLeft();
            }
        }
        if (cima){
            int next_y = _player_ship->gety() - _player_ship->getVelocidade();
            bool colision = checkCollision(x1, next_y, x2, y2, width1, height1, width2, height2);
            if (_player_ship->gety() > 24 && !colision){
                _player_ship->moveUp();
            }
        }
        if (baixo){
            int next_y = _player_ship->gety() + _player_ship->getVelocidade();
            bool colision = checkCollision(x1, next_y, x2, y2, width1, height1, width2, height2);
            if (_player_ship->gety() < 510 && !colision){
            _player_ship->moveDown();       
            }     
        }

        window.clear();
        window.draw(maze_sprite);

        _player_ship->move();

        _player_ship->getShipSprite()->setPosition(_player_ship->getx(), _player_ship->gety());
        window.draw(*_player_ship->getShipSprite());

        _first_enemy->getShipSprite()->setPosition(245, 150);
        window.draw(*_first_enemy->getShipSprite());

        shot_sprite.setPosition(566, 400);
        window.draw(shot_sprite);
       


       if(checkCollision(x1,y1,x2,y2,width1,height1,width2,height2)){
        std::cout<< "colidiu  dois" << std::endl;
       }


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


bool Window::checkCollision(int x1, int y1, int x2, int y2, int width1, int height1, int width2, int height2) {

    bool colisao_1 = ((y1 > y2) && (y1 < y2 + height2)) || ((y1 + height1 > y2) && (y1 + height1 < y2 + height2));
    bool colisao_2 = ((x1 > x2) && (x1 < x2 + width2)) || ((x1 + width1 > x2) && (x1 + width1 < x2 + width2));

    bool colisao = colisao_1 && colisao_2;

    if (colisao){

        return true;
    }
    return false;
}