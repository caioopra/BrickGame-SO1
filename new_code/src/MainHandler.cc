#include "../include/MainHandler.h"

__BEGIN_API

std::shared_ptr<GameHandler> MainHandler::gameHandler;

Thread* MainHandler::gameLoopThread;
Thread* MainHandler::windowThread;
Thread* MainHandler::keyboardThread;
Thread* MainHandler::playerThread;
Thread* MainHandler::collisionHandlerThread;
Thread* MainHandler::enemiesHandlerThread;

Game* MainHandler::game;
Window* MainHandler::window;
Keyboard* MainHandler::keyboard;
PlayerHandler* MainHandler::playerHandler;
CollisionHandler* MainHandler::collisionHandler;
EnemiesHandler* MainHandler::enemiesHandler;

void MainHandler::exec(void * name) {
    gameHandler = std::make_shared<GameHandler>();
    gameHandler->initialize();

    gameLoopThread = new Thread(gameExec);
    playerThread = new Thread(playerExec);
    windowThread = new Thread(windowExec);
    keyboardThread = new Thread(keyboardExec);
    enemiesHandlerThread = new Thread(enemiesHandlerExec);
    collisionHandlerThread = new Thread(collisionHandlerExec);

    gameLoopThread->join();
    windowThread->join();
    playerThread->join();
    keyboardThread->join();
    collisionHandlerThread->join();

    delete gameLoopThread;
    delete windowThread;
    delete playerThread;
    delete keyboardThread;
    delete collisionHandlerThread;
}

// gets the events and insert them into the gameHandler or deal with them as necessary
void MainHandler::gameExec() {
    std::cout<< " GAME HANDLER EXEC" << std::endl;
    game = new Game();
    game->setGameHandler(gameHandler);
    game->run();

    delete game;
}

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

void MainHandler::enemiesHandlerExec() {
    std::cout<< " ENEMIES EXEC" << std::endl;
    enemiesHandler = new EnemiesHandler();
    enemiesHandler->setGameHandler(gameHandler);
    enemiesHandler->run();
    delete enemiesHandler;
}

void MainHandler::collisionHandlerExec() {
    collisionHandler = new CollisionHandler();
    collisionHandler->setGameHandler(gameHandler);
    collisionHandler->run();

    delete collisionHandler;
}

__END_API