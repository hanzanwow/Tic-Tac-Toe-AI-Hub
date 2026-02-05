#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <memory>
#include "XOBot.h"

class XOBot;
class player;

class TicTacToe
{
private:
    std::unique_ptr<player> ptrPlayer;
    std::unique_ptr<XOBot> ptrBot;

protected:
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerIcon;
    char computerIcon;
    bool running;
    int PlayerWins;
    int ComputerWins;
    int Ties;

    void drawBoard();
    void resetBoard();
    char checkGameStatus();
    bool PlayAgain();
    void updateScore(char status);
    void displayScore();
    void Show_status(char status);

public:
    // Application Programming Interface (API)
    //  API สำหรับให้ Player Bot เรียกใช้

    // ขอลงตำแหน่งนี้
    bool placeMove(int index, char icon)
    {
        if (index >= 0 && index < 9 && spaces[index] == ' ')
        {
            spaces[index] = icon;
            return true;
        }
        return false;
    }
    // ขอดูช่องนี้คือตัวอะไร
    char getGridAt(int index) const
    {
        if (index >= 0 && index < 9)
            return spaces[index];
        return '\0'; // Error
    }
    // Getter สำหรบให icon
    char getPlayerIcon() const { return playerIcon; }
    char getComputerIcon() const { return computerIcon; }

    TicTacToe();
    ~TicTacToe();
    void runGame();
};
class player
{
private:
    TicTacToe *game;

public:
    player(TicTacToe *t) : game(t) {}
    void Move();
};

#endif
