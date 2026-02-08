#include "TicTacToe.h"
#include "Player.h"
#include "Utils.h"
#include <iostream>
#include <limits>
#include <vector>

void player::Move()
{
    int number;
    while (true)
    {
        std::cout << "Enter number (1-9) to place your 'X': ";
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << Color::RED << "Invalid input. Please enter a number." << Color::RESET << std::endl;
            continue;
        }
        number--; //(1-9) - 1
        if (game->placeMove(number, game->getPlayerIcon()))
            break;
        else
            std::cerr << Color::YELLOW << "Invalid move or spot taken." << Color::RESET << std::endl;
    }
}