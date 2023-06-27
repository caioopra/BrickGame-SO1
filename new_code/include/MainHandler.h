#ifndef MAINHANDLER_H
#define MAINHANDLER_H

#include <iostream>
#include <memory>

#include "GameHandler.h"
#include "Keyboard.h"
#include "CollisionHandler.h"
#include "PlayerHandler.h"
#include "EnemiesHandler.h"
#include "Window.h"

#include "threading/thread.h"
#include "threading/traits.h"

__BEGIN_API

class MainHandler {
   public:
    MainHandler(){}
    ~MainHandler(){}

    static void exec(void * name);

    static void windowExec();
    static void keyboardExec();
    static void playerExec();
    static void enemiesHandlerExec();
    static void collisionHandlerExec();
    static void enemyExec1();
    static void enemyExec2();
    static void enemyExec3();
    static void enemyExec4();

    static std::shared_ptr<GameHandler> gameHandler;

    static Thread* windowThread;
    static Thread* keyboardThread;
    static Thread* playerThread;
    static Thread* enemiesHandlerThread;
    static Thread* collisionHandlerThread;
    static Thread* enemyThread1;
    static Thread* enemyThread2;
    static Thread* enemyThread3;
    static Thread* enemyThread4;

    static PlayerHandler* playerHandler;
    static EnemiesHandler* enemiesHandler;
    static Window* window;
    static Keyboard* keyboard;
    static CollisionHandler* collisionHandler;
    static EnemyShip* enemy1;
    static EnemyShip* enemy2;
    static EnemyShip* enemy3;
    static EnemyShip* enemy4;
};

__END_API

#endif