#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <memory>
#include <array>
#include <vector>
#include "XOBot.h"

class XOBot;
class player;

class TicTacToe
{
private:
    std::unique_ptr<player> ptrPlayer;
    std::unique_ptr<XOBot> ptrBot;

protected:
    std::array<char, 9> spaces = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    const char playerIcon;
    const char computerIcon;
    bool running = true;
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
    /*
    #########==================================================#########
    #########-----Application Programming Interface (API)------#########
    #########==================================================#########
                    API สำหรับให้ Player,Bot เรียกใช้
    */

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
    // Getter สำหรับให้ icon
    char getPlayerIcon() const { return playerIcon; }
    char getComputerIcon() const { return computerIcon; }
    // ขอดูช่องนี้คือตัวอะไร
    char getGridAt(int index) const
    {
        if (index < 0 || index >= static_cast<int>(spaces.size()))
            return '\0';
        return spaces.at(index);
    }
    // ขอดูว่าช่องไหนมีอะไรบ้าง
    auto &getMap() const
    {
        return spaces;
    }


    // constructor
    TicTacToe();
    // deconstructor
    ~TicTacToe();

    void runGame();
};
class player
{
private:
    TicTacToe *game;

public:
    player(TicTacToe *API) : game(API) {}
    void Move();
};

#endif
