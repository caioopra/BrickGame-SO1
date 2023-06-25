#include <iostream>
#include "../include/Game.h"
#include "../include/GameHandler.h"
#include "../include/threading/system.h"
#include "../include/MainHandler.h"

__USING_API

int main() {
    System::init(&MainHandler::exec);
    return 0;
}
