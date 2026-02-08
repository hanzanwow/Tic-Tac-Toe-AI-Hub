# Tic-Tac-Toe AI Hub 🎮

A classic Tic-Tac-Toe game reimagined with **Modern C++ (OOP)**. This project demonstrates the implementation of AI algorithms ranging from random moves to the unbeatable **Minimax Algorithm**.

## 🚀 Features
- **Object-Oriented Design:** Clean architecture using C++ Classes and Smart Pointers.
- **3 Difficulty Modes:**
  - 🟢 **Easy:** Random moves (Relaxing).
  - 🟡 **Medium:** Smart AI that can attack and defend, but makes human-like mistakes.
  - 🔴 **Hard:** Unbeatable AI using the **Minimax Algorithm**.
- **Interactive UI:** Console-based interface with colorful text feedback.

## 🛠️ Tech Stack
- **Language:** C++ (Standard 17/20/23)
- **Compiler:** MSYS2 / G++
   > Note: Please install the latest version of G++ before use.
- **IDE:** VS Code(Text editor)

## ⚙️ Installation & How to Run

1. **Prerequisites**
   Ensure you have a C++ compiler installed (e.g., G++, Clang, or MSVC) that supports C++17 or later.

2. **Clone the repository** (or download files)
   ```bash
   git clone [https://github.com/YourUsername/TicTacToe-AI.git](https://github.com/YourUsername/TicTacToe-AI.git)
   ```

## Compile the source code Open your terminal in the project folder and run:
   ```Bash
   g++ *.cpp -o gamehub -std=c++23 -Wall -Wextra
   ```

(Note: You can change -std=c++23 to -std=c++17 if your compiler is older.)

## Run the game
  ```Bash
  ./gamehub
  ```

## 🎮 How to Play
1. The game is played on a 3x3 grid.

2. You are 'X' and the Computer is 'O'.

3. Input a number 1-9 to place your mark on the grid.

4. The first to get 3 marks in a row (horizontal, vertical, or diagonal) wins.

| Key | Action  |
| :---: | :--- |
| **1 - 9** | Choose a location on the board to place an 'X' mark. |
| **Y / N** | Play Again / Exit |
| **Enter** | Confirm |

> **Note:** Positions 1-9 are arranged according to the Numpad keys on the keyboard (1=bottom left, 9=top right) or in normal order (1=top left), depending on the player's viewing angle.

## 👤 Author

**Pattaradanai Amazutsumi**
- Discord: **haszan._**
- GitHub: **@hanzanwow**
- Email: **natoodxd@gmail.com (or) 2511311215@tni.ac.th**

## 🎓 Project BackGround
Created during my **1st year, 2nd semester** as a Computer Engineer student,as a project submission for the CPE-113 course.
<br>
This project demostrates my understanding of AI algorithms and OOP principles.

## ✨ What I Learned
- Implementing Minimax Algorithm from scratch
- Object-Oriented Desing in Modern C++
- Game state management and AI decision-making
- Lambda function
- Smart pointers
- Basic API

## 🚀 Future Improvements
- [ ] Add GUI using SFML
- [ ] Implement Alpha-Beta Pruning
