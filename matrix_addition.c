#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    int matrixA[MAX_ROWS][MAX_COLS];
    int matrixB[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int i, j;

    // Input dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Validate dimensions
    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid dimensions! Please enter dimensions between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    // Input first matrix
    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input second matrix
    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Display result
    printf("\nMatrix A + Matrix B = \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
