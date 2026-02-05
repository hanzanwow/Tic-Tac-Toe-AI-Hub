#include <iostream>
#include "MenuSystem.h" // เรียกใช้เมนู
#include "TicTacToe.h"  // เรียกใช้เกม XO
#include "SnakeGame.h"
#include "Utils.h"
#include <ctime>

// Run code -> Terminal -> g++ *.cpp -o gamehub -> Enter
// ./gamehub
int main()
{

    MenuSystem menu;
    int choice = 1;
    //do
    //{
        //menu.displayHeader();
        //choice = menu.showMenu();

        switch (choice)
        {
        case 1:
        {
            std::srand(static_cast<unsigned int>(std::time(0)));
            TicTacToe xo;
            xo.runGame();
            break;
        }
        case 2:
        {
            // Snake snake(1,2);
            break;
        }
        case 3:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    //} while (choice != 3);
    return 0;
}
