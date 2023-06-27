#include "../include/EnemiesHandler.h"

__BEGIN_API

EnemiesHandler::EnemiesHandler()
{
}

void EnemiesHandler::run()
{
    while (!Config::isGameOver)
    {
        if (!_gameHandler->_is_paused)
        {

            moveEnemies();


            sf::Time newTime;
            std::list<EnemyShip *>::iterator enemy;
            for (enemy = _gameHandler->_enemies->begin(); enemy != _gameHandler->_enemies->end();)
            {
                EnemyShip *myEnemy = *enemy;
                if (myEnemy->_dead)
                {
                    newTime = myEnemy->_revive_clock.getElapsedTime();
                    // std::cout << newTime.asMilliseconds() <<" "<< myEnemy->_revive_clock.getElapsedTime().asMilliseconds()<< std::endl;
                    if (newTime.asMilliseconds() > 2000)
                    {
                        myEnemy->setDead(false);
                        myEnemy->_x = myEnemy->initial_x;
                        myEnemy->_y = myEnemy->initial_y;
                        newTime = myEnemy->_revive_clock.restart();
                    }
                }
                if (myEnemy->canShot())
                {
                    myEnemy->createShot();
                }
                myEnemy->_ship_sprite.setPosition(myEnemy->_x, myEnemy->_y);
                enemy++;
            }
        }

        Thread::yield();
    }
}

void EnemiesHandler::colisionEnemies()
{
    int x1, x2, y1, y2, width1, height1, width2, height2;
    bool colisao_1, colisao_2, colisao;
    std::list<EnemyShip *>::iterator enemy;
    for (enemy = _gameHandler->_enemies->begin(); enemy != _gameHandler->_enemies->end();)
    {
        EnemyShip *myEnemy = *enemy;
        std::list<EnemyShip *>::iterator enemy_2;
        for (enemy_2 = _gameHandler->_enemies->begin(); enemy_2 != _gameHandler->_enemies->end();)
        {
            EnemyShip *myEnemy_2 = *enemy_2;

            x1 = myEnemy->_x;
            y1 = myEnemy->_y;
            x2 = myEnemy_2->_x;
            y2 = myEnemy_2->_y;

            colisao_1 = std::min(y1, y1 + 100) < std::max(y2, y2 + 100) && std::max(y1, y1 + 100) > std::min(y2, y2 + 100);
            colisao_2 = std::min(x1, x1 + 100) < std::max(x2, x2 + 100) && std::max(x1, x1 + 100) > std::min(x2, x2 + 100);

            colisao = colisao_1 && colisao_2;
            if (colisao && (enemy != enemy_2))
            {
                if (myEnemy->getDirection() == Ship::UP)
                {
                    myEnemy->changeDirection(Ship::LEFT);
                    myEnemy_2->changeDirection(Ship::DOWN);
                }
                else if (myEnemy->getDirection() == Ship::DOWN)
                {
                    myEnemy->changeDirection(Ship::RIGHT);
                    myEnemy_2->changeDirection(Ship::UP);
                }
                else if (myEnemy->getDirection() == Ship::RIGHT)
                {
                    myEnemy->changeDirection(Ship::UP);
                    myEnemy_2->changeDirection(Ship::LEFT);
                }
                else
                {
                    myEnemy->changeDirection(Ship::DOWN);
                    myEnemy_2->changeDirection(Ship::RIGHT);
                }
            }
            else
            {
                if (myEnemy->getDirection() == Ship::UP)
                {
                    if (myEnemy->_y - myEnemy->_velocidade > 0)
                    {
                        if (myEnemy->canMove())
                        {
                            myEnemy->move();
                        }
                    }
                    else
                    {
                        myEnemy->changeDirection(Ship::DOWN);
                    }
                }
                else if (myEnemy->getDirection() == Ship::DOWN)
                {
                    if (myEnemy->_y + myEnemy->_velocidade < 512)
                    {
                        if (myEnemy->canMove())
                        {
                            myEnemy->move();
                        }
                    }
                    else
                    {
                        myEnemy->changeDirection(Ship::UP);
                    }
                }
                else if (myEnemy->getDirection() == Ship::RIGHT)
                {
                    if (myEnemy->_x + myEnemy->_velocidade < 512)
                    {
                        if (myEnemy->canMove())
                        {
                            myEnemy->move();
                        }
                    }
                    else
                    {
                        myEnemy->changeDirection(Ship::LEFT);
                    }
                }
                else
                {
                    if (myEnemy->_x - myEnemy->_velocidade > 0)
                    {
                        if (myEnemy->canMove())
                        {
                            myEnemy->move();
                        }
                    }
                    else
                    {
                        myEnemy->changeDirection(Ship::RIGHT);
                    }
                }
            }
            enemy_2++;
        }
        enemy++;
    }
}
void EnemiesHandler::colisionEnemies2()
{  
    int cima,baixo,esquerda,direita;

    std::list<EnemyShip *>::iterator enemy;
    for (enemy = _gameHandler->_enemies->begin(); enemy != _gameHandler->_enemies->end();)
    {
        EnemyShip *myEnemy = *enemy;
        if(myEnemy->_movement_algorithm == 0) {
            cima= 0;
            esquerda=0;
            baixo=230;
            direita=230;
        } else if(myEnemy->_movement_algorithm == 1) {
            cima=270;
            esquerda=0;
            baixo=512;
            direita=230;
        
        } else if(myEnemy->_movement_algorithm == 2) {
            cima=0;
            esquerda=270;
            baixo=230;
            direita=512;
        } else{
            cima=270;
            esquerda=270;
            baixo=512;
            direita=512;
        }

        if (myEnemy->getDirection() == Ship::UP)
        {
            if (myEnemy->_y - myEnemy->_velocidade > cima)
            {
                if (myEnemy->canMove())
                {
                    myEnemy->move();
                }
            }
            else
            {
                myEnemy->changeDirection(Ship::LEFT);
            }
        }
        else if (myEnemy->getDirection() == Ship::DOWN)
        {
            if (myEnemy->_y + myEnemy->_velocidade < baixo)
            {
                if (myEnemy->canMove())
                {
                    myEnemy->move();
                }
            }
            else
            {
                myEnemy->changeDirection(Ship::RIGHT);
            }
        }
        else if (myEnemy->getDirection() == Ship::RIGHT)
        {
            if (myEnemy->_x + myEnemy->_velocidade < direita)
            {
                if (myEnemy->canMove())
                {
                    myEnemy->move();
                }
            }
            else
            {

                myEnemy->changeDirection(Ship::UP);
            }
        }
        else
        {
            if (myEnemy->_x - myEnemy->_velocidade > esquerda)
            {
                if (myEnemy->canMove())
                {
                    myEnemy->move();
                }
            }
            else
            {
                myEnemy->changeDirection(Ship::DOWN);
            }
        }
    enemy++;
    }
}

void EnemiesHandler::moveEnemies()
{
    if(_gameHandler->_movementType){
        colisionEnemies();
    }else{
        colisionEnemies2();
    }
}

__END_API
