#include "../include/CollisionHandler.h"


__BEGIN_API

CollisionHandler::CollisionHandler() {
    std::cout << "COLLISION HANDLER INSTANTIATED" << std::endl;
}

void CollisionHandler::run() {

    std::cout << "COLLISION HANDLER - CHECKING FOR COLLISION" << std::endl;
    Thread::yield();
}

__END_API