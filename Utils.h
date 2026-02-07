#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

struct Color
{
    inline static constexpr const char *CYAN = "\033[36m";
    inline static constexpr const char *BLUE = "\033[34m";
    inline static constexpr const char *MAGENTA = "\033[35m";
    inline static constexpr const char *BOLD_MAGENTA = "\033[1;35m";
    inline static constexpr const char *RESET = "\033[0m";
    inline static constexpr const char *GREEN = "\033[32m";
    inline static constexpr const char *RED = "\033[31m";
    inline static constexpr const char *YELLOW = "\033[33m";
};
// Color::RED
#endif