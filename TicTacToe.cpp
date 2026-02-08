#include "TicTacToe.h"
#include "Utils.h"
#include <iostream>
#include <limits>
#include <vector>
#include <memory>

TicTacToe::TicTacToe() : mode(random_model()), playerIcon('X'), computerIcon('O'), running(true), PlayerWins(0u), ComputerWins(0u), Ties(0u)
{
    // สร้าง object player และ bot โดยส่ง this (ตัวเกมปัจจุบัน) เข้าไป
    ptrPlayer = std::make_unique<player>(this);
    ptrBot = std::make_unique<XOBot>(this);
}
TicTacToe::~TicTacToe() { std::cout << "Tic Tac Toe has Delate successfully" << std::endl; }
Difficulty TicTacToe::random_model(){ auto random = std::rand() % 3; return static_cast<Difficulty>(random); }
void TicTacToe::runGame()
{
    while (true)
    {
        std::system("cls");
        mode = random_model();
        resetBoard();
        running = true;

        auto count = 0u;
        auto status = ' ';
        while (running)
        {
            drawBoard();

            ptrPlayer->Move();
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
            break;
        
    }
}
void TicTacToe::displayScore()
{
    std::cout << Color::GREEN << "Player (X): " << Color::RESET << PlayerWins << Color::MAGENTA << "  |  Computer (O): " << Color::RESET << ComputerWins << Color::YELLOW << " | Ties: " << Color::RESET << Ties << std::endl;
    std::cout << Color::CYAN << " | Mode: ";
    switch (mode)
    {
    case Difficulty::Easy: std::cout << "Easy"; break;
    case Difficulty::Medium: std::cout << "Medium"; break;
    case Difficulty::Hard: std::cout << "Hard"; break;
    }
    std::cout << Color::RESET << std::endl;
}
void TicTacToe::drawBoard()
{
    std::cout << std::endl;
    displayScore();
    std::cout << "==== XO XO XO====";
    std::cout << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces.at(0) << "  |  " << spaces.at(1) << "  |  " << spaces.at(2) << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces.at(3) << "  |  " << spaces.at(4) << "  |  " << spaces.at(5) << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces.at(6) << "  |  " << spaces.at(7) << "  |  " << spaces.at(8) << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "==== XO XO XO====";
    std::cout << std::endl;
}
void TicTacToe::resetBoard()
{
    // for (auto& i : spaces)
    //     i = ' ';
    spaces.fill(' ');
}
char TicTacToe::checkGameStatus()
{
    /*
    std::array<std::array<3>,8> wins = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // นอน
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // ตั้ง
        {0, 4, 8},
        {2, 4, 6} // ทแยง
    };
    */
    // check ตั้ง นอน
    for (auto i = 0; i < 3; i++)
    {
        auto rStart = i * 3;
        // ตรวจแนวตั้ง
        if (spaces.at(rStart) != ' ' && spaces.at(rStart) == spaces.at(rStart + 1) && spaces[rStart] == spaces.at(rStart + 2))
            return spaces.at(rStart);
        // ตรวจแนวนอน
        if (spaces.at(i) != ' ' && spaces.at(i) == spaces.at(i + 3) && spaces.at(i) == spaces.at(i + 6))
            return spaces.at(i);
    }
    // ทแยง
    if (spaces.at(0) != ' ' && spaces.at(0) == spaces.at(4) && spaces.at(4) == spaces.at(8))
        return spaces.at(0);
    if (spaces.at(2) != ' ' && spaces.at(2) == spaces.at(4) && spaces.at(4) == spaces.at(6))
        return spaces.at(2);
    // ยังไม่จบ
    for (const auto &i : spaces)
        if (i == ' ')
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
    char playagain;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        std::cout << "Play again?(y/n): ";
        std::cin >> playagain;
        playagain = std::tolower(playagain);
        
    } while (playagain != 'y' && playagain != 'n');

    return (playagain == 'y');
}
void TicTacToe::Show_status(char status)
{
    if (status == playerIcon)
        std::cout << Color::GREEN << "YOU WIN!" << Color::RESET << std::endl;
    else if (status == computerIcon)
        std::cout << Color::RED << "YOU LOSE!" << Color::RESET << std::endl;
    else if (status == 'T')//Tie
        std::cout << Color::YELLOW << "IT'S A TIE!" << Color::RESET << std::endl;
}