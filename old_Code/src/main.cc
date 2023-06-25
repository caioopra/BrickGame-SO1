#include "../include/window.h"
#include "../include/PlayerShip.h"
#include "../include/EnemyShip.h"
#include "../include/keyboard.h"
#include "../include/CollisionHandler.h"

int main(void) {
    Game* game = new Game();
    game->init();
    // Window* window = new Window(game);
    // window->run();

    return 0;
}
