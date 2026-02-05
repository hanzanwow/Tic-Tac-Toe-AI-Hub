#include "TicTacToe.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <math.h>
#include <vector>
#include <memory>

TicTacToe::TicTacToe()
{
    running = true;
    playerIcon = 'X';
    computerIcon = 'O';
    PlayerWins = 0u;
    ComputerWins = 0u;
    Ties = 0u;
    // สร้าง object player และ bot โดยส่ง this (ตัวเกมปัจจุบัน) เข้าไป
    ptrPlayer = std::make_unique<player>(this);
    ptrBot = std::make_unique<XOBot>(this);

    resetBoard();
}
TicTacToe::~TicTacToe()
{
    std::cout << "Tic Tac Toe has Delate successfully" << std::endl;
}
void TicTacToe::runGame()
{
    while (true)
    {
        resetBoard();
        running = true;

        int count = 0;
        char status = ' ';
        while (running)
        {
            drawBoard();

            ptrPlayer->Move();
            drawBoard();
            count++;

            if (count >= 3)
            {
                status = checkGameStatus();
                if (status != ' ')
                {
                    running = false;
                    continue;
                }
            }

            ptrBot->Move();
            drawBoard();
            count++;

            if (count >= 3)
            {
                status = checkGameStatus();
                if (status != ' ')
                {
                    running = false;
                    continue;
                }
            }
        }
        updateScore(status);
        drawBoard();
        Show_status(status);
        if (!PlayAgain())
        {
            break;
        }
    }
}
void TicTacToe::displayScore()
{
    std::cout << Color::GREEN << "Player (X): " << Color::RESET << PlayerWins << Color::MAGENTA << "  |  Computer (O): " << Color::RESET << ComputerWins << Color::YELLOW << " | Ties: " << Color::RESET << Ties << std::endl;
}
void TicTacToe::drawBoard()
{
    /*
            |               |
            |      x        |
            |               |
    --------|---------------|---------
            |               |
            |               |   o
            |               |
    --------|---------------|---------
            |               |
            |               |
            |               |
    */
    // std::system("cls");
    std::cout << std::endl;
    std::cout << std::endl;
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
void TicTacToe::resetBoard()
{
    for (int i = 0; i < 9; i++)
    {
        spaces[i] = ' ';
    }
}
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
char TicTacToe::checkGameStatus()
{
    /*
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // นอน
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // ตั้ง
        {0, 4, 8},
        {2, 4, 6} // ทแยง
    };
    */
    // check ตั้ง นอน
    for (int i = 0; i < 3; i++)
    {
        int rStart = i * 3;
        if (spaces[rStart] != ' ' && spaces[rStart] == spaces[rStart + 1] && spaces[rStart] == spaces[rStart + 2])
            return spaces[rStart];
        if (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i] == spaces[i + 6])
            return spaces[i];
    }
    // ทแยง
    if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
        return spaces[0];
    if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
        return spaces[2];
    // ยังไม่จบ
    for (int i = 0; i < 9; i++)
        if (spaces[i] == ' ')
            return ' ';
    // เสมอ
    return 'T';
}
void TicTacToe::updateScore(char status)
{
    if (status == playerIcon)
        PlayerWins++;
    else if (status == computerIcon)
        ComputerWins++;
    else if (status == 'T')
        Ties++;
}
bool TicTacToe::PlayAgain()
{
    std::string playagain;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        std::cout << "Play again?(y/n): ";
        std::getline(std::cin, playagain);
        for (char &c : playagain)
        {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    } while (playagain != "y" && playagain != "n");

    return playagain == "y";
}
void TicTacToe::Show_status(char status)
{
    if (status == playerIcon)
        std::cout << Color::GREEN << "YOU WIN!" << Color::RESET << std::endl;
    else if (status == computerIcon)
        std::cout << Color::RED << "YOU LOSE!" << Color::RESET << std::endl;
    else if (status == 'T')
        std::cout << Color::YELLOW << "IT'S A TIE!" << Color::RESET << std::endl;
}