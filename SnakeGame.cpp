#include <vector>
#include <iostream>
#include <deque>
#include "SnakeGame.h"
#include <cstdlib>
#include "Utils.h"
Snake::Snake(int start_x, int start_y){
    body.push_front({start_x, start_y});
    direction = stop;
}

void Snake::move(bool eaten){
    Point new_head = body.front();
    if (direction == left) new_head.x--;
    if (direction == right) new_head.x++;
    if (direction == up) new_head.y--;
    if (direction == down) new_head.y++;
    
    body.push_front(new_head);
        if (!eaten){
            body.pop_back();
        }
}
bool Snake::checkSelfCollision(){
    for (size_t i = 1; i < body.size(); i++){
        if (body.front().x == body[i].x && body.front().y == body[i].y){
            return true;
        }
        return false;
        }
    }

