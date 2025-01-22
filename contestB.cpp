#include <bits/stdc++.h>
using namespace std;

// Recursive function to find and print all the possible permutation for the N-Queens to be placed on the board
void solveNQueens(int board[], int row, int n, int &solutionCount) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":";
        for (int i = 0; i < n; i++) cout <<  board[i] + 1 << " ";// (+1) to convert 0-based to 1-based index and print it 
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {

        int check=1;
        for (int i = 0; i < row; i++) {
            // Check same column , left diagonal and right diaginal 
            if (board[i] == col || abs(board[i]-col)==abs(row-i) ) {
                check=0;
                break;
            }
        }
        if (check) {
            board[row] = col; // Place the queen
            solveNQueens(board, row + 1, n, solutionCount); // Recurse for next row
            // Backtrack: Remove the queen
            board[row] = -1;
        }
    }
}

int main() {
    int n;
    // printf("Enter the value of N: ");
    cin >> n;

    // declare an array board to store the possible permutation of N queen on the board
    int board[n];
    int solutionCount = 0;

    // Initialize the board
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    // function to compute all the possible permutation on N queen 
    solveNQueens(board, 0, n, solutionCount);
    // cout << "No. of solution: " << solutionCount <<"\n";

    return 0;
}
