#include "../include/MainHandler.h"

__BEGIN_API

std::shared_ptr<GameHandler> MainHandler::gameHandler;

Thread* MainHandler::gameLoopThread;
Thread* MainHandler::windowThread;
Thread* MainHandler::keyboardThread;
Thread* MainHandler::playerThread;
Thread* MainHandler::collisionHandlerThread;
Thread* MainHandler::enemiesHandlerThread;
Thread* MainHandler::enemyThread1;
Thread* MainHandler::enemyThread2;
Thread* MainHandler::enemyThread3;
Thread* MainHandler::enemyThread4;

Window* MainHandler::window;
Keyboard* MainHandler::keyboard;
PlayerHandler* MainHandler::playerHandler;
CollisionHandler* MainHandler::collisionHandler;
EnemiesHandler* MainHandler::enemiesHandler;
EnemyShip* MainHandler::enemy1;
EnemyShip* MainHandler::enemy2;
EnemyShip* MainHandler::enemy3;
EnemyShip* MainHandler::enemy4;

void MainHandler::exec(void * name) {
    gameHandler = std::make_shared<GameHandler>();
    gameHandler->initialize();

     = new Thread(gameExec);
    playerThread = new Thread(playerExec);
    windowThread = new Thread(windowExec);
    keyboardThread = new Thread(keyboardExec);
    enemyThread1 = new Thread(enemyExec1);
    enemyThread2 = new Thread(enemyExec2);
    enemyThread3 = new Thread(enemyExec3);
    enemyThread4 = new Thread(enemyExec4);
    collisionHandlerThread = new Thread(collisionHandlerExec);
    enemiesHandlerThread = new Thread(enemiesHandlerExec);

    windowThread->join();
    playerThread->join();
    keyboardThread->join();
    collisionHandlerThread->join();
    enemyThread1->join();
    enemyThread2->join();
    enemyThread3->join();
    enemyThread4->join();
    enemiesHandlerThread->join();

    delete windowThread;
    delete playerThread;
    delete keyboardThread;
    delete collisionHandlerThread;
    delete enemyThread1;
    delete enemyThread2;
    delete enemyThread3;
    delete enemyThread4;
    delete enemiesHandlerThread;
}

// gets the events and insert them into the gameHandler or deal with them as necessary
void MainHandler::windowExec() {
    std::cout<< " WINDOW EXEC" << std::endl;
    window = new Window();
    window->setGameHandler(gameHandler);
    window->run();

    delete window;
}

void MainHandler::keyboardExec() {
    std::cout<< " KEYBOARD EXEC" << std::endl;
    keyboard = new Keyboard();
    keyboard->setGameHandler(gameHandler);
    keyboard->run();

    delete keyboard;
}

void MainHandler::playerExec() {
    std::cout<< " PLAYER EXEC" << std::endl;
    playerHandler = new PlayerHandler();
    playerHandler->setGameHandler(gameHandler);
    std::cout<< " PLAYER EXEC RUN" << std::endl;
    playerHandler->run();
    delete playerHandler;
}


void MainHandler::collisionHandlerExec() {
    collisionHandler = new CollisionHandler();
    collisionHandler->setGameHandler(gameHandler);
    collisionHandler->run();

    delete collisionHandler;
}

void MainHandler::enemyExec1() {
    enemy1 = new EnemyShip(0, 20, 20);

    enemy1->run();

    delete enemy1;
}

void MainHandler::enemyExec2() {
    enemy2 = new EnemyShip(1, 20, 400);
    enemy2->run();

    delete enemy2;
}

void MainHandler::enemyExec3() {
    enemy3 = new EnemyShip(2, 400, 20);
    enemy3->run();

    delete enemy3;
}

void MainHandler::enemyExec4() {
    enemy4 = new EnemyShip(3, 400, 400);
    enemy4->run();

    delete enemy4;
}

void MainHandler::enemiesHandlerExec() {
    std::cout<< " ENEMIES EXEC" << std::endl;
    enemiesHandler = new EnemiesHandler();
    enemiesHandler->setGameHandler(gameHandler);
    gameHandler->_enemies->push_back(enemy1);
    gameHandler->_enemies->push_back(enemy2);
    gameHandler->_enemies->push_back(enemy3);
    gameHandler->_enemies->push_back(enemy4);
    enemiesHandler->run();

    delete enemiesHandler;
}
__END_API