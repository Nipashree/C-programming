#include <stdio.h>
#include <stdbool.h>
#define N 8  // Change N to the size of your chessboard (4, 8, etc.)

int board[N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row)
            return false;
    }
    return true;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int row) {
    if (row == N) {
        printSolution(); // Found a valid solution
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;       // Place queen
            solveNQueens(row + 1);  // Recur for next row
            // Backtrack happens automatically when loop continues
        }
    }
}

int main() {
    solveNQueens(0);
    return 0;
}
