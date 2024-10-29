# Game of Life

This project implements **Conway's Game of Life** in C, simulating a cellular automaton on a 5x5 grid for 7 generations. The user sets an initial configuration, and the program evolves the grid based on the rules of Life.

## Game Rules
1. Any live cell with fewer than two or more than three live neighbors dies (underpopulation or overpopulation).
2. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

Each generation is computed based on the previous one, with changes applied simultaneously to all cells.

## How to Use
1. The user is prompted to enter the initial configuration as a series of cell offsets (e.g., `6,11,12,16`).
   - The offsets correspond to live cells, starting with the top-left cell as `0` and moving right in row-major order.
2. The program then displays each generation on the grid up to the 6th generation.

## Code Structure
- `printGrid(int grid[SIZE][SIZE])`: Displays the current grid with live cells as 'X' and dead cells as '.'.
- `nextGeneration(int grid[SIZE][SIZE])`: Calculates the next generation based on the rules of Life.
- `main()`: Initializes the grid based on user input and runs the simulation for the specified number of generations.

## Compilation
To compile the code, open a terminal in the project directory and run:
```bash
gcc -o life life.c
