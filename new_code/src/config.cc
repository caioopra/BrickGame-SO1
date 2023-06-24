#include "../include/Config.h"
#include "../include/threading/traits.h"

__BEGIN_API

// Semaphore* Config::finishedSemaphore = new Semaphore();
// Semaphore* Config::pausedSemaphore = new Semaphore();
// Semaphore* Config::gameOverSemaphore = new Semaphore();

bool Config::isFinished = false;
bool Config::isPaused = false;
bool Config::isGameOver = false;

int Config::height = 560;
int Config::width = 814;
int Config::playableHeight = 600; 
int Config::playableWidth = 600; 
int Config::infoHeight = 560;
int Config::infoWidth = 569;
int Config::max_lives = 3;

// void Config::deleteSemaphores()
// {
//     delete finishedSemaphore;
//     delete pausedSemaphore;
//     delete gameOverSemaphore;
// }

__END_API