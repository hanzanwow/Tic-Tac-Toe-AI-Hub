#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "XOBot.h"

class player;
class TicTacToe
{
private:
    friend class player;
    player *ptrPlayer;
protected:
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerIcon = 'X';
    char computerIcon = 'O';
    bool running = true;
    int PlayerWins = 0;
    int ComputerWins = 0;
    int Ties = 0;
    XOBot bot;

    void drawBoard();
    void resetBoard();
    char checkWinner();
    bool checkTie();
    bool PlayAgain();
    void updateScore(char winner);
    void displayScore();

public:
    TicTacToe();
    void runGame();
};

class player
{
private:
    TicTacToe *game;
    void playerMove();
    public:
    player(TicTacToe *t) : game(t) {}
    void playerMove();
};

#endif
