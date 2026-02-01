#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "XOBot.h"

class TicTacToe
{
private:
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    int PlayerWins = 0;
    int ComputerWins = 0;
    int Ties = 0;
    XOBot bot;

    void drawBoard();
    void resetBoard();
    void playerMove();
    void computerMove();
    char checkWinner();
    bool checkTie();
    bool PlayAgain();
    void updateScore();
    void displayScore();

public:
    TicTacToe();
    void runGame();
};

#endif
