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

        // Adjust input to 0-based index (User enters 1-9, Array uses 0-8)
        number--;

        // Attempt to place the move via the Game API
        // If placeMove returns true, the move was successful.
        if (game->placeMove(number, game->getPlayerIcon()))
            break;
        else
            std::cerr << Color::YELLOW << "Invalid move or spot taken." << Color::RESET << std::endl;
    }
}