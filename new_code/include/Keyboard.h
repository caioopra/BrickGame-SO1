#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "GameHandler.h"
#include "PlayerShip.h"
#include "threading/traits.h"
#include "threading/thread.h"

__BEGIN_API

class Keyboard {
   public:
    Keyboard();

    void run();

    void receiveEvent(sf::Event event);
    bool can_shot = true;

    std::shared_ptr<GameHandler> getGameHandler() { return _gameHandler; }
    void setGameHandler(std::shared_ptr<GameHandler> ptr) { _gameHandler = ptr; }

   private:
    std::shared_ptr<GameHandler> _gameHandler;
};

__END_API

#endif
