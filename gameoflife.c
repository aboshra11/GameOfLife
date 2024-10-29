#include <stdio.h>
#define SIZE 5
#define GEN 7

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
}

void nextGeneration(int grid[SIZE][SIZE]) {
    int temp[SIZE][SIZE] = {0};

    // Apply the Game of Life rules
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int liveNeighbors = 0;

            // Count live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // Skip the cell itself
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && grid[ni][nj]) {
                        liveNeighbors++;
                    }
                }
            }

            // Apply the rules
            if (grid[i][j] && (liveNeighbors < 2 || liveNeighbors > 3)) temp[i][j] = 0;
            else if (!grid[i][j] && liveNeighbors == 3) temp[i][j] = 1;
            else temp[i][j] = grid[i][j];
        }
    }

    // Update the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};

    // Initialize grid with user input
    printf("Enter the initial configuration (0 for dead, 1 for alive):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Simulate for GEN generations
    for (int gen = 0; gen < GEN; gen++) {
        printf("Generation %d:\n", gen);
        printGrid(grid);
        nextGeneration(grid);
    }

    return 0;
}

