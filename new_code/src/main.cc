#include <iostream>
#include "../include/Game.h"
#include "../include/GameHandler.h"

__USING_API

int main() {
    GameHandler* gamehandler = new GameHandler();
    Game* game = new Game();
    game->run();

    return 0;
}
