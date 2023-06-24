#ifndef CONFIGS_H
#define CONFIGS_H

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

};

__END_API

#endif
