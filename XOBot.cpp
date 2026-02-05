#include "XOBot.h"
#include "Utils.h"
#include "TicTacToe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

Difficulty XOBot::random_model()
{
    int r = std::rand() % 3;
    return static_cast<Difficulty>(r);
}
void XOBot::Move()
{
    Difficulty mode = random_model();
    switch (mode)
    {
    case Difficulty::Easy:
        EasyMode();
        break;
    case Difficulty::Medium:
        EasyMode();
        //MediumMode();
        break;
    case Difficulty::Hard:
        EasyMode();
        //HardMode();
        break;
    }
}
void XOBot::EasyMode()
{
    int number;
    number = rand() % 9;
    while (true)
    {
        number = std::rand() % 9;
        if (game->placeMove(number, game->getComputerIcon()))
            break;
    }
}