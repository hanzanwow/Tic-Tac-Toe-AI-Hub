#ifndef XOBOT_H
#define XOBOT_H

#include <array>

class TicTacToe;

class XOBot
{
private:
    TicTacToe *game;
    char PLAYER;
    char AI;

    void EasyMode();
    void MediumMode();

    class HardMode
    {
    private:
        TicTacToe *game;
        char AI;
        char PLAYER;
        bool isWinner(const std::array<char, 9> &board, const char &player) const;
        bool isBoardFull(const std::array<char, 9> &board) const;
        int minimax(std::array<char, 9> &board, bool isMaximizing);
        int findBestMove();

    public:
        HardMode(TicTacToe* API, char ai, char human);
        ~HardMode() = default;
        void Hard_Move();
    };

public:
    HardMode hard;
    XOBot(TicTacToe *API);
    void Move();
};
#endif
