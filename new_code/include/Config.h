#ifndef CONFIGS_H
#define CONFIGS_H
#include "threading/thread.h"
#include "threading/traits.h"
#include <iostream>   
#include <ucontext.h>

__BEGIN_API

class Config {
public:
    static bool isFinished;
    static bool isPaused;
    static bool isGameOver;

    static int width;
    static int height;
    static int playableWidth;
    static int playableHeight;
    static int infoWidth;
    static int infoHeight;
    static int max_lives;

};

__END_API

#endif
