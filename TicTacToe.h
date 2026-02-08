#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <memory>
#include <array>
#include "XOBot.h"
#include "Player.h"

class XOBot;
class player;
enum class Difficulty
{
    Easy,
    Medium,
    Hard
};

class TicTacToe
{
private:
    std::unique_ptr<player> ptrPlayer;
    std::unique_ptr<XOBot> ptrBot;
    
    Difficulty mode;
    std::array<char, 9> spaces = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    const char playerIcon;
    const char computerIcon;
    bool running;
    int PlayerWins;
    int ComputerWins;
    int Ties;

    Difficulty random_model();
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
    char getPositionAt(int index) const { return spaces.at(index); }
    // ขอดูว่าช่องไหนมีอะไรบ้าง
    auto &getMap() const{return spaces;}
    //ขอดู mode
    auto &getMode() const {return mode;}

    // constructor
    TicTacToe();
    // deconstructor
    ~TicTacToe();

    void runGame();
};
#endif
