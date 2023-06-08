#include "../include/window.h"
#include "../include/keyboard.h"

bool cima, baixo, direita, esquerda = false;


Window::Window(PlayerShip* player, EnemyShip* enemy1) {
    _player_ship = player;
    _first_enemy = enemy1;

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

    Keyboard keyboard;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                 window.close();
                 break;
            
            // key pressed
            case sf::Event::KeyPressed:
                keyboard.run(event);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                    esquerda = true;
                    
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    direita = true;
                    
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    baixo =true;
                   
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    cima = true;
                    
                } else {
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                }
                break;

            case sf::Event::KeyReleased:
                if(event.key.code  == sf::Keyboard::Left) {
                    std::cout << "Keyboard esquerda solto!" << std::endl;
                    esquerda = false;
                   
                } else if(event.key.code  == sf::Keyboard::Right) {
                    std::cout << "Keyboard direita solto!" << std::endl;
                    direita = false;
                    
                } else if(event.key.code == sf::Keyboard::Down) {
                    std::cout << "Keyboard para baixo solto!" << std::endl;
                    baixo =false;
                    
                } else if(event.key.code == sf::Keyboard::Up) {
                    std::cout << "Keyboard para cima solto!" << std::endl;
                    cima = false;
                    
                } else {
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                }
                break;
            }
        }

        if (direita){
            if (_player_ship->getx() < 510){
            _player_ship->moveRight();
            }
        }
        if (esquerda){
            if (_player_ship->getx() > 24){
                _player_ship->moveLeft();
            }
        }
        if (cima){
            if (_player_ship->gety() > 24){
                _player_ship->moveUp();
            }
        }
        if (baixo){
            if (_player_ship->gety() < 510){
            _player_ship->moveDown();       
            }     
        }

        window.clear();
        window.draw(maze_sprite);

        _player_ship->getShipSprite()->setPosition(_player_ship->getx(), _player_ship->gety());
        window.draw(*_player_ship->getShipSprite());

        _first_enemy->getShipSprite()->setPosition(245, 150);
        window.draw(*_first_enemy->getShipSprite());

        shot_sprite.setPosition(566, 400);
        window.draw(shot_sprite);
       
       if(_player_ship->getShipSprite()->getGlobalBounds().intersects(_first_enemy->getShipSprite()->getGlobalBounds())){
            std::cout<< "colidiu" << std::endl;
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
