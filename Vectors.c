#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to display a matrix
void displayMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Gaussian elimination to check rank
int gaussianElimination(double** matrix, int rows, int cols) {
    int rank = 0;

    for (int col = 0; col < cols; col++) {
        // Find pivot row
        int pivotRow = -1;
        for (int row = rank; row < rows; row++) {
            if (matrix[row][col] != 0.0) {
                pivotRow = row;
                break;
            }
        }

        // If no pivot found, move to next column
        if (pivotRow == -1) continue;

        // Swap rows to move the pivot row to current position
        if (pivotRow != rank) {
            for (int j = 0; j < cols; j++) {
                double temp = matrix[rank][j];
                matrix[rank][j] = matrix[pivotRow][j];
                matrix[pivotRow][j] = temp;
            }
        }

        // Normalize the pivot row
        for (int j = col + 1; j < cols; j++) {
            matrix[rank][j] /= matrix[rank][col];
        }
        matrix[rank][col] = 1.0;

        // Eliminate below pivot
        for (int row = rank + 1; row < rows; row++) {
            double factor = matrix[row][col];
            for (int j = col; j < cols; j++) {
                matrix[row][j] -= factor * matrix[rank][j];
            }
        }

        rank++;
    }
    return rank;
}

// Function to check linear dependence/independence
bool checkLinearIndependence(double** vectors, int numVectors, int vectorSize) {
    // Copy vectors into a matrix
    double** matrix = (double**)malloc(numVectors * sizeof(double*));
    for (int i = 0; i < numVectors; i++) {
        matrix[i] = (double*)malloc(vectorSize * sizeof(double));
        for (int j = 0; j < vectorSize; j++) {
            matrix[i][j] = vectors[i][j];
        }
    }

    // Display the matrix
    printf("Input Matrix:\n");
    displayMatrix(matrix, numVectors, vectorSize);

    // Calculate the rank of the matrix
    int rank = gaussianElimination(matrix, numVectors, vectorSize);

    // Clean up
    for (int i = 0; i < numVectors; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Return whether the vectors are linearly independent
    return rank == numVectors;
}

int main() {
    int numVectors, vectorSize;

    printf("Enter number of vectors: ");
    scanf("%d", &numVectors);

    printf("Enter size of each vector: ");
    scanf("%d", &vectorSize);

    // Allocate memory for vectors
    double** vectors = (double**)malloc(numVectors * sizeof(double*));
    for (int i = 0; i < numVectors; i++) {
        vectors[i] = (double*)malloc(vectorSize * sizeof(double));
    }

    // Input vectors
    printf("Enter the vectors:\n");
    for (int i = 0; i < numVectors; i++) {
        printf("Vector %d:\n", i + 1);
        for (int j = 0; j < vectorSize; j++) {
            scanf("%lf", &vectors[i][j]);
        }
    }

    // Check linear independence
    if (checkLinearIndependence(vectors, numVectors, vectorSize)) {
        printf("The vectors are linearly independent.\n");
    } else {
        printf("The vectors are linearly dependent.\n");
    }

    // Free memory
    for (int i = 0; i < numVectors; i++) {
        free(vectors[i]);
    }
    free(vectors);

    return 0;
}
