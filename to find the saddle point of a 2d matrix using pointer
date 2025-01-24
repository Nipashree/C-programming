#include <stdio.h>

#define ROW 3
#define COL 3

void findSaddlePoint(int (*matrix)[COL], int rows, int cols) {
    int i, j, k, minRow, colIndex, isSaddle;
    int found = 0;

    for (i = 0; i < rows; i++) {
        minRow = *(*(matrix + i));  
        colIndex = 0;

        for (j = 1; j < cols; j++) {
            if (*(*(matrix + i) + j) < minRow) {
                minRow = *(*(matrix + i) + j);
                colIndex = j;
            }
        }
        isSaddle = 1;
        for (k = 0; k < rows; k++) {
            if (*(*(matrix + k) + colIndex) > minRow) {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle) {
            printf("Saddle point found at position (%d, %d) with value %d\n", i, colIndex, minRow);
            found = 1;
        }
    }

    if (!found) {
        printf("No saddle point found in the matrix.\n");
    }
}

int main() {
    int matrix[ROW][COL] = {
        {3, 8, 7},
        {5, 9, 2},
        {6, 4, 1}
    };

    printf("Given matrix:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    findSaddlePoint(matrix, ROW, COL);

    return 0;
}
