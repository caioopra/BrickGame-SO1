#include "../include/window.h"
#include "../include/PlayerShip.h"
#include "../include/EnemyShip.h"

int main(void) {
    PlayerShip* player = new PlayerShip(1);
    EnemyShip* enemy1 = new EnemyShip(2);

    Window* window = new Window(player, enemy1);

    window->run();

    return 0;
}
