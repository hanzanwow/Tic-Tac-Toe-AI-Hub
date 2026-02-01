#ifndef SnakeGame_H
#define SnakeGame_H
#include <deque>

enum Direction {
    stop = 0,
    left = 1,
    right = 2,
    up = 3,
    down = 4
};

struct Point { int x,y;};

class Snake{
    public:
    std::deque<Point> body;
    Direction direction;

    Snake(int start_x, int start_y);
    void move(bool eaten);
    bool checkSelfCollision();

};

class Food {
    public:
    Point position;
    void generate(int width, int height){
        position.x = rand()%width;
        position.y = rand()%height;
    }
};

class GameController{
    private:
    Snake snake;
    Food food;
    int width, height, score;
    bool Gameover;

    public:
    GameController();
    void run();
    void process_input();
    void update();
    void render();
};

#endif