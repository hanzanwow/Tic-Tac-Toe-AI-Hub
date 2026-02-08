#include "XOBot.h"
#include "Utils.h"
#include "TicTacToe.h"
#include <iostream>
#include <algorithm>
#include <array>

XOBot::XOBot(TicTacToe *API) : game(API), PLAYER(API->getPlayerIcon()), AI(API->getComputerIcon()), hard(API, AI, PLAYER) {}
void XOBot::Move()
{
    //// Difficulty mode = Difficulty::Hard; //test function hard
    switch (game->getMode())
    {
    case Difficulty::Easy:
        EasyMode();
        break;
    case Difficulty::Medium:
        MediumMode();
        break;
    case Difficulty::Hard:
        hard.Hard_Move();
        break;
    }
}
void XOBot::EasyMode()
{
    auto number = 0;
    while (true)
    {
        number = std::rand() % 9;
        if (game->placeMove(number, game->getComputerIcon()))
            break;
    }
}
void XOBot::MediumMode()
{
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

    auto findWinningSpot = [&](char targetIcon) -> int
    {
        // ดูทุกความเป็นไปได้
        for (const auto &line : wins_stage)
        {
            auto countTarget = 0;
            auto countEmpty = 0;
            auto TargetIndex = -1;

            // ดูทุกความเป็นไปได้
            for (auto index : line)
            {
                auto now = game->getPositionAt(index);
                if (now == targetIcon)
                    countTarget++;

                else if (now == ' ')
                {
                    countEmpty++;
                    TargetIndex = index;
                }
            }

            // ใกล้ชนะ
            if (countTarget == 2 && countEmpty == 1)
            {
                return TargetIndex;
            }
        }

        // ไม่ชนะไม่แพ้
        return -1;
    };

    auto change = std::rand() % 100;
    if (change > 50)
    {
        // เดินตาที่มีโอกาศขนะ
        auto winMove = findWinningSpot(AI);
        if (winMove != -1)
        {
            game->placeMove(winMove, AI);
            std::cout << "AI Medium Mode attacks at " << winMove + 1 << std::endl;
            return;
        }

        // เดินตาที่มีโอกาสป้องกันแพ้
        auto blockMove = findWinningSpot(PLAYER);
        if (blockMove != -1)
        {
            game->placeMove(blockMove, AI);
            std::cout << "AI Medium Mode blocks at " << blockMove + 1 << std::endl;
            return;
        }
    }

    // ไม่ชนะไม่แพ้
    EasyMode();
}

XOBot::HardMode::HardMode(TicTacToe *API, char ai, char human) : game(API), AI(ai), PLAYER(human) {}
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
        auto bestScore = -10000;
        for (auto i{0uz}; i < board.size(); i++)
        {
            if (board.at(i) == ' ')
            {
                board.at(i) = AI; // ลองใส่
                bestScore = std::max(bestScore, minimax(board, false));
                board.at(i) = ' '; // เอาออก
            }
        }
        return bestScore;
    }
    else
    {
        auto bestScore = 10000;
        for (auto i{0uz}; i < board.size(); i++)
        {
            if (board.at(i) == ' ')
            {
                board.at(i) = PLAYER;
                bestScore = std::min(bestScore, minimax(board, true));
                board.at(i) = ' ';
            }
        }
        return bestScore;
    }
}
int XOBot::HardMode::findBestMove()
{
    std::array<char, 9> TestBoard = game->getMap();
    auto bestScore = -1000;
    auto move = -1;

    std::cout << "--- AI Hard mode Thinking ---" << std::endl;

    for (auto i{0uz}; i < TestBoard.size(); i++)
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
    std::cout << "-------------------" << std::endl;

    return move;
}
void XOBot::HardMode::Hard_Move()
{
    auto AI_Move = findBestMove();
    game->placeMove(AI_Move, game->getComputerIcon());
}