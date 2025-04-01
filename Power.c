#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a matrix
double** allocateMatrix(int size) {
    double** matrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)malloc(size * sizeof(double));
    }
    return matrix;
}

// Function to free a matrix
void freeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices
void multiplyMatrices(double** A, double** B, double** result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to compute power of a matrix
void powerMatrix(double** matrix, double** result, int size, int power) {
    // Initialize result as the identity matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Temporary matrix to store intermediate results
    double** temp = allocateMatrix(size);

    for (int p = 0; p < power; p++) {
        multiplyMatrices(result, matrix, temp, size);

        // Copy temp into result
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = temp[i][j];
            }
        }
    }

    freeMatrix(temp, size);
}

int main() {
    int size, power;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter the power to which the matrix should be raised: ");
    scanf("%d", &power);

    // Allocate memory for the matrix and result
    double** matrix = allocateMatrix(size);
    double** result = allocateMatrix(size);

    // Input matrix
    printf("Enter the elements of the matrix row by row:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Compute power of the matrix
    powerMatrix(matrix, result, size, power);

    // Output the result
    printf("\nMatrix raised to power %d:\n", power);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    freeMatrix(matrix, size);
    freeMatrix(result, size);

    return 0;
}
