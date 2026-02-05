#ifndef XOBOT_H
#define XOBOT_H

class TicTacToe;
enum class Difficulty
{
    Easy,
    Medium,
    Hard
};
class XOBot
{
private:
    TicTacToe *game;
    Difficulty random_model();
    void EasyMode();
    void MediumMode();
    void HardMode();

public:
    XOBot(TicTacToe *t) : game(t) {}
    void Move();
};

#endif
