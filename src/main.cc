#include "../include/window.h"
#include "../include/PlayerShip.h"
#include "../include/EnemyShip.h"
#include "../include/keyboard.h"

int main(void) {
    PlayerShip* player = new PlayerShip(1);
    EnemyShip* enemy1 = new EnemyShip(2);
    Keyboard* keyboard = new Keyboard(player);

    Window* window = new Window(player, enemy1, keyboard);

    window->run();

    return 0;
}
