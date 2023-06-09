#include "../include/window.h"
#include "../include/PlayerShip.h"
#include "../include/EnemyShip.h"
#include "../include/keyboard.h"
#include "../include/CollisionHandler.h"

int main(void) {
    PlayerShip* player = new PlayerShip(1);
    EnemyShip* enemy1 = new EnemyShip(2);
    Keyboard* keyboard = new Keyboard(player);
    CollisionHandler* collision = new CollisionHandler(player, enemy1);

    Window* window = new Window(player, enemy1, keyboard, collision);

    window->run();

    return 0;
}
