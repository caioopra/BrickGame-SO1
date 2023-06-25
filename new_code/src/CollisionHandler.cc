#include "../include/CollisionHandler.h"
#include "../include/Config.h"

__BEGIN_API

CollisionHandler::CollisionHandler() {
    std::cout << "COLLISION HANDLER INSTANTIATED" << std::endl;
}

void CollisionHandler::run() {
    while(!Config::isGameOver){
    std::cout << "COLLISION HANDLER - CHECKING FOR COLLISION" << std::endl;
    Thread::yield();
    }
}

__END_API