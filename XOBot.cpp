#include "XOBot.h"
#include "Utils.h"
#include "TicTacToe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <array>

XOBot::XOBot(TicTacToe *API) : game(API), PLAYER(API->getPlayerIcon()), AI(API->getComputerIcon()), hard(API, AI, PLAYER){ }
Difficulty XOBot::random_model()
{
    int r = std::rand() % 3;
    return static_cast<Difficulty>(r);
}
void XOBot::Move()
{
    //Difficulty mode = random_model();
    Difficulty mode = Difficulty::Hard;
    switch (mode)
    {
    case Difficulty::Easy:
        EasyMode();
        break;
    case Difficulty::Medium:
        EasyMode(); // MediumMode();
        break;
    case Difficulty::Hard:
        hard.Hard_Move();
        break;
    }
}
void XOBot::EasyMode()
{
    int number;
    while (true)
    {
        number = std::rand() % 9;
        if (game->placeMove(number, game->getComputerIcon()))
            break;
    }
}
void XOBot::MediumMode()
{
    // waiting
}
XOBot::HardMode::HardMode(TicTacToe *ptr, char ai, char human) : game(ptr), AI(ai), PLAYER(human){}
bool XOBot::HardMode::isWinner(const std::array<char, 9> &board, const char &player) const
{
    // 3ช่อง 8 เส้น
    const std::array<std::array<int, 3>, 8> wins_stage =
        {{
            {0, 1, 2}, // นอน
            {3, 4, 5}, // นอน
            {6, 7, 8}, // นอน
            {0, 3, 6}, // ตั้ง
            {1, 4, 7}, // ตั้ง
            {2, 5, 8}, // ตั้ง
            {0, 4, 8}, // ทแยง
            {2, 4, 6}  // ทแยง
        }};

    for (const auto &line : wins_stage)
        if ((board.at(line.at(0)) == player) && (board.at(line.at(1)) == player) && (board.at(line.at(2)) == player))
            return true;
    return false;
}
bool XOBot::HardMode::isBoardFull(const std::array<char, 9> &board) const
{
    for (const auto &space : board)
        if (space == ' ')
            return false;
    return true;
}
int XOBot::HardMode::minimax(std::array<char, 9> &board, bool isMaximizing)
{
    if (isWinner(board, AI))
        return 10;
    if (isWinner(board, PLAYER))
        return -10;
    if (isBoardFull(board))
        return 0;

    if (isMaximizing)
    {
        int bestScore = -10000;
        for (auto i = 0; i < board.size(); i++)
        {
            if (board[i] == ' ')
            {
                board[i] = AI; // ลองใส่
                bestScore = std::max(bestScore, minimax(board, false));
                board[i] = ' '; // เอาออก
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 10000;
        for (auto i = 0; i < board.size(); i++)
        {
            if (board[i] == ' ')
            {
                board[i] = PLAYER;
                bestScore = std::min(bestScore, minimax(board, true));
                board[i] = ' ';
            }
        }
        return bestScore;
    }
}
int XOBot::HardMode::findBestMove()
{
    std::array<char, 9> TestBoard = game->getMap();
    int bestScore = -1000;
    int move = -1;

    std::cout << std::endl << "--- AI Thinking ---" << std::endl;

    for (auto i = 0; i < TestBoard.size(); i++)
    {
        if (TestBoard.at(i) == ' ')
        {
            TestBoard.at(i) = AI;
            int score = minimax(TestBoard, false);
            TestBoard.at(i) = ' ';

            std::cout << "Slot " << i + 1 << " : Score = " << score << std::endl;

            if (score > bestScore)
            {
                bestScore = score;
                move = i;
            }
        }
    }

    std::cout << ">>> AI Chose Slot: " << move + 1 << " (Best Score: " << bestScore << ")" << std::endl;
    std::cout << "-------------------"<< std::endl;

    return move;
}
void XOBot::HardMode::Hard_Move()
{
    int AI_Move = findBestMove();
    game->placeMove(AI_Move, game->getComputerIcon());
}