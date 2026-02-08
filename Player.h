#ifndef Player_H
#define Player_H

class TicTacToe;
class player
{
private:
    TicTacToe *game;

public:
    player(TicTacToe *API) : game(API) {}
    void Move();
};

#endif