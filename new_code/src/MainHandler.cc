#include "../include/MainHandler.h"

__BEGIN_API

std::shared_ptr<GameHandler> MainHandler::gameHandler;

Thread* MainHandler::gameLoopThread;
Thread* MainHandler::windowThread;
Thread* MainHandler::keyboardThread;
Thread* MainHandler::playerThread;
Thread* MainHandler::collisionHandlerThread;

Game* MainHandler::game;
Window* MainHandler::window;
Keyboard* MainHandler::keyboard;
PlayerShip* MainHandler::playerShip;
CollisionHandler* MainHandler::collisionHandler;

void MainHandler::exec() {
    gameHandler = std::make_shared<GameHandler>();
    gameHandler->initialize();

    gameLoopThread = new Thread(gameExec);
    windowThread = new Thread(windowExec);
    keyboardThread = new Thread(keyboardExec);
    playerThread = new Thread(playerExec);
    collisionHandlerThread = new Thread(collisionHandlerExec);

    gameLoopThread->join();
    windowThread->join();
    playerThread->join();
    collisionHandlerThread->join();
    keyboardThread->join();

    delete gameLoopThread;
    delete windowThread;
    delete keyboardThread;
    delete playerThread;
    delete collisionHandlerThread;
}

// gets the events and insert them into the gameHandler or deal with them as necessary
void MainHandler::gameExec() {
    game = new Game();
    game->setGameHandler(gameHandler);
    game->run();

    delete game;
}

void MainHandler::windowExec() {
    window = new Window();
    window->setGameHandler(gameHandler);
    window->run();

    delete window;
}

void MainHandler::keyboardExec() {
    keyboard = new Keyboard(playerShip);
    keyboard->setGameHandler(gameHandler);
    keyboard->run();

    delete keyboard;
}

void MainHandler::playerExec() {
    playerShip = new PlayerShip();
    playerShip->setGameHandler(gameHandler);
    playerShip->run();

    delete playerShip;
}

void MainHandler::collisionHandlerExec() {
    collisionHandler = new CollisionHandler();
    collisionHandler->setGameHandler(gameHandler);
    collisionHandler->run();

    delete collisionHandler;
}

__END_API