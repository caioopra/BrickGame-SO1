#ifndef MAINHANDLER_H
#define MAINHANDLER_H

#include <iostream>
#include <memory>

#include "GameHandler.h"
#include "Keyboard.h"
#include "Game.h"
#include "CollisionHandler.h"
 
#include "threading/thread.h"
#include "threading/traits.h"


__BEGIN_API

class MainHandler {
   public:
    MainHandler(){}
    ~MainHandler(){}

    static void exec();

    static void gameExec();
    static void windowExec();
    static void keyboardExec();
    static void playerExec();
    static void collisionHandlerExec();

    static std::shared_ptr<GameHandler> gameHandler;

    static Thread* gameLoopThread;
    static Thread* windowThread;
    static Thread* keyboardThread;
    static Thread* playerThread;
    static Thread* collisionHandlerThread;

    static Game* game;
    static Window* window;
    static Keyboard* keyboard;
    static PlayerShip* playerShip;
    static CollisionHandler* collisionHandler;
};

__END_API

#endif