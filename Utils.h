#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

struct Color
{
    inline static const char *CYAN = "\033[36m";
    inline static const char *BLUE = "\033[34m";
    inline static const char *MAGENTA = "\033[35m";
    inline static const char *BOLD_MAGENTA = "\033[1;35m";
    inline static const char *RESET = "\033[0m";
    inline static const char *GREEN = "\033[32m";
    inline static const char *RED = "\033[31m";
    inline static const char *YELLOW = "\033[33m";
};
//Color::RED
#endif