#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    void init();
    void run();

protected:
    bool gameOver;
    bool spawnEnemies;

    int score;    
    int speed;
};

#endif
