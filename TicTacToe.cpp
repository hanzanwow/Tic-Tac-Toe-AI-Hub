#include "TicTacToe.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib> 
#include <cctype>  
#include <limits>  
#include <algorithm>

TicTacToe::TicTacToe()
{
    playerIcon = 'X';
    computerIcon = 'O';
    PlayerWins = 0u;
    ComputerWins = 0u;
    Ties = 0u;
    resetBoard();
}
void TicTacToe::runGame()
{

}
void TicTacToe::displayScore()
{
    std::cout << Color::GREEN << "Player (X): " << Color::RESET << PlayerWins << Color::MAGENTA << "  |  Computer (O): " << Color::RESET << ComputerWins << Color::YELLOW << " | Ties: " << Color::RESET << Ties << std::endl;
}
void TicTacToe::drawBoard()
{
    std::system("clear");
    displayScore();
    std::cout << "==== XO XO XO====";
    std::cout << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "==== XO XO XO====";
    std::cout << std::endl;
}
void player::playerMove()
{
    int number;
    while (true)
    {
        std::cout << "Enter number (1-9) to place your 'X': ";
        std::cin >> number;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << Color::RED << "Invalid input. Please enter a number." << Color::RESET << std::endl;
        }

        number--;
        if(number >= 0 && number <= 8)
        {
            if(game->spaces[number] == ' ')
                game->spaces[number] = game->playerIcon;
            else
                std::cerr << Color::YELLOW << "That spot is already taken." << Color::RESET << std::endl;
        }
        else
            std::cerr << Color::RED << "Invalid spot. Please enter a number between 1 and 9." << Color::RESET << std::endl;
    }
}

// bot move random minimax
/*----code here----*/

void TicTacToe::updateScore(char winner)
{
    if(winner == playerIcon)
        PlayerWins++;
    else if (winner == computerIcon)
        ComputerWins++;
    else
        Ties++;
}