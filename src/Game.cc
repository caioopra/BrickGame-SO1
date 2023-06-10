#include "../include/Game.h"

Game::Game() {
    
}

void Game::init() {
    gameOver = false;
    spawnEnemies = false;
    score = 0;
    speed = 1;
    _player_ship = new PlayerShip();
    EnemyShip *enemy = new EnemyShip();
    _enemies_list.push_back(enemy);

    _keyboard = new Keyboard(_player_ship);
    _collision = new CollisionHandler(_player_ship, enemy);
}
