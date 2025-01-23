#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the cell is valid and safe for the rat to move
bool isSafe(int maze[][20], int x, int y, int visited[][20], int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to find all paths in the maze
void solveMazeUtil(int maze[][20], int x, int y, int visited[][20], char path[], int step, int n) {
    // Base case: If the rat has reached the destination
    if (x == n - 1 && y == n - 1) {
        path[step] = '\0'; // Null-terminate the string
        printf("Path: %s\n", path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Move down (D)
    if (isSafe(maze, x + 1, y, visited, n)) {
        path[step] = 'D';
        solveMazeUtil(maze, x + 1, y, visited, path, step + 1, n);
    }

    // Move left (L)
    if (isSafe(maze, x, y - 1, visited, n)) {
        path[step] = 'L';
        solveMazeUtil(maze, x, y - 1, visited, path, step + 1, n);
    }

    // Move right (R)
    if (isSafe(maze, x, y + 1, visited, n)) {
        path[step] = 'R';
        solveMazeUtil(maze, x, y + 1, visited, path, step + 1, n);
    }

    // Move up (U)
    if (isSafe(maze, x - 1, y, visited, n)) {
        path[step] = 'U';
        solveMazeUtil(maze, x - 1, y, visited, path, step + 1, n);
    }

    // Backtrack: Unmark the current cell
    visited[x][y] = 0;
}

// Function to solve the maze
void solveMaze(int maze[][n], int n) {
    int visited[20][20] = {0}; // Keeps track of visited cells
    char path[400];            // Stores the path as a string (enough for n=20)
    
    printf("All possible paths:\n");
    solveMazeUtil(maze, 0, 0, visited, path, 0, n);
}

int main() {
    int n;
    int maze[20][20];

    printf("Enter the size of the maze (n x n): ");
    scanf("%d", &n);

    printf("Enter the maze matrix (1 for open cell, 0 for blocked cell):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        printf("No paths exist as start or end is blocked.\n");
        return 0;
    }

    solveMaze(maze, n);

    return 0;
}
