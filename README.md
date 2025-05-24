# Mini Pacman Game in C

This project is a simple console-based Pacman-like game written in C, where you control a player on a 16x16 board, collect ECTS points, avoid walls, and aim to reach the exit.

## Features

- Randomly generated 16x16 game board with:
    - Player (P) starting in the center
    - Collectible items: `1`, `2` (worth 8 ECTS each)
    - Walls: `#`
    - Exit: `X`
- Move with `W`, `A`, `S`, `D` keys (case-insensitive)
- Collect enough items to pass through some walls
- The game displays total ECTS, total moves, and updates the board after each action
- Game ends when you reach the exit (`X`)

## How to Run

1. Compile the code:
    ```bash
    gcc Muhammed_Korkmaz.c -o mini_pacman
    ```
2. Run the program:
    ```bash
    ./mini_pacman
    ```

## How to Play

- Control the player (P) using:
    - `W` or `w`: move up
    - `A` or `a`: move left
    - `S` or `s`: move down
    - `D` or `d`: move right
- Collect `1` and `2` to increase your ECTS
- Some walls require collecting enough `1` or `2` before you can pass through
- Your goal is to reach `X` (the exit) with as many ECTS as possible

## Author

Muhammed Korkmaz  
Gebze Technical University  
Student ID: 220104004043
