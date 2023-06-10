#include "../include/window.h"
#include <list>
#include <iterator>
#include "../include/Shot.h"
#include "../include/CollisionHandler.h"

Window::Window(Game* game) {
    _game = game;
    _player_ship = game->getPlayer();
    _window.create(sf::VideoMode(900, 560), "SFML works!");
    // _window = new sf::RenderWindow(sf::VideoMode(900, 560), "SFML works!");
    // sf::RenderWindow _window(sf::VideoMode(900, 560), "SFML works!");
    load_and_bind_textures();
}

void Window::run() {
    // Link: https://www.sfml-dev.org/tutorials/2.5/window-events.php
    // https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php
    _window.setKeyRepeatEnabled(false);

    _window.setFramerateLimit(10);

    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _window.close();
                    break;

                case sf::Event::KeyPressed:
                    _game->getKeyboard()->receiveEvent(event);

                case sf::Event::KeyReleased:
                    _game->getKeyboard()->receiveEvent(event);
            }
        }

        update();
        int x1, x2, y1, y2, width1, height1, width2, height2;
        x1 = _game->getPlayer()->getShipSprite()->getGlobalBounds().left;
        y1 = _game->getPlayer()->getShipSprite()->getGlobalBounds().top;
        width1 = _game->getPlayer()->getShipSprite()->getGlobalBounds().width;
        height1 = _game->getPlayer()->getShipSprite()->getGlobalBounds().height;
        EnemyShip* _enemy = _game->getEnemies().front();
        x2 = _enemy->getShipSprite()->getGlobalBounds().left;
        y2 = _enemy->getShipSprite()->getGlobalBounds().top;
        width2 = _enemy->getShipSprite()->getGlobalBounds().width;
        height2 = _enemy->getShipSprite()->getGlobalBounds().height;

        if (_game->getCollisionHandler()->checkCollision(x1, y1, x2, y2, width1, height1, width2, height2)) {
            std::cout << "colidiu  dois" << std::endl;
        }
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


void Window::update(){
    _window.clear();

    _window.draw(maze_sprite);
    
    std::list<Shot>::iterator it;
    std::list<Shot>& g = _player_ship->getShots();

    for (it = g.begin(); it != g.end();){
        std::list<EnemyShip*>::iterator enemy_it;
        std::list<EnemyShip*> enemies = _game->getEnemies();    
        for (enemy_it = enemies.begin(); enemy_it != enemies.end();){
            std::cout << enemies.size() << std::endl;
            EnemyShip* my_enemy = *enemy_it;
            
            int x1, x2, y1, y2, width1, height1, width2, height2;
            x1 = my_enemy->getShipSprite()->getGlobalBounds().left;
            y1 = my_enemy->getShipSprite()->getGlobalBounds().top;
            width1 = my_enemy->getShipSprite()->getGlobalBounds().width;
            height1 = my_enemy->getShipSprite()->getGlobalBounds().height;

            x2 = it->getShotSprite()->getGlobalBounds().left;
            y2 = it->getShotSprite()->getGlobalBounds().top;
            width2 = it->getShotSprite()->getGlobalBounds().width;
            height2 = it->getShotSprite()->getGlobalBounds().height;
            if (_game->getCollisionHandler()->check(x1, y1, x2, y2, width1, height1, width2, height2)){
                std::cout<< "remover" << std::endl;
                it = g.erase(it);
                enemy_it = enemies.erase(enemy_it);
            }else{
            it->move();
            it->getShotSprite()->setPosition(it->getx(), it->gety());
            _window.draw(*it->getShotSprite());
            my_enemy->getShipSprite()->setPosition(my_enemy->getx(), my_enemy->gety());
            _window.draw(*my_enemy->getShipSprite());
            ++it;
            ++enemy_it;
            }
    }   
    }

    // std::list<EnemyShip*>::iterator enemy_it;
    // std::list<EnemyShip*> enemies = _game->getEnemies();

    // for (enemy_it = enemies.begin(); enemy_it != enemies.end(); ++enemy_it){
    //     std::cout << enemies.size() << std::endl;
    //     EnemyShip* my_enemy = *enemy_it;
    //     my_enemy->getShipSprite()->setPosition(my_enemy->getx(), my_enemy->gety());
    //     _window.draw(*my_enemy->getShipSprite());
    // }
    
    _player_ship->getShipSprite()->setPosition(_player_ship->getx(), _player_ship->gety());
    _window.draw(*_player_ship->getShipSprite());



    shot_sprite.setPosition(566, 400);
    _window.draw(shot_sprite);

    _window.display();

    
}
