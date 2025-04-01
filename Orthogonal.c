#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6  // Convergence threshold for power iteration
#define MAX_ITER 1000 // Maximum number of iterations

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

// Function to multiply a matrix and a vector
void matrixVectorMultiply(double** matrix, double* vector, double* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;
        for (int j = 0; j < size; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

// Function to normalize a vector
void normalizeVector(double* vector, int size) {
    double norm = 0.0;
    for (int i = 0; i < size; i++) {
        norm += vector[i] * vector[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < size; i++) {
        vector[i] /= norm;
    }
}

// Function to compute eigenvalue using Rayleigh quotient
double computeEigenvalue(double** matrix, double* eigenvector, int size) {
    double* temp = (double*)malloc(size * sizeof(double));
    matrixVectorMultiply(matrix, eigenvector, temp, size);

    double numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < size; i++) {
        numerator += temp[i] * eigenvector[i];
        denominator += eigenvector[i] * eigenvector[i];
    }

    free(temp);
    return numerator / denominator;
}

// Power Iteration Method to compute eigenvalue and eigenvector
void powerIteration(double** matrix, double* eigenvalue, double* eigenvector, int size) {
    // Initialize the eigenvector with random values
    for (int i = 0; i < size; i++) {
        eigenvector[i] = 1.0; // Initial values
    }
    normalizeVector(eigenvector, size);

    double* tempVector = (double*)malloc(size * sizeof(double));
    double previousEigenvalue = 0.0;

    for (int iter = 0; iter < MAX_ITER; iter++) {
        matrixVectorMultiply(matrix, eigenvector, tempVector, size);
        normalizeVector(tempVector, size);

        *eigenvalue = computeEigenvalue(matrix, tempVector, size);

        // Check for convergence
        if (fabs(*eigenvalue - previousEigenvalue) < EPSILON) {
            break;
        }

        previousEigenvalue = *eigenvalue;

        // Update eigenvector
        for (int i = 0; i < size; i++) {
            eigenvector[i] = tempVector[i];
        }
    }

    free(tempVector);
}

// Function to diagonalize a matrix
void diagonalizeMatrix(double** matrix, double** P, double** D, int size) {
    double* eigenvector = (double*)malloc(size * sizeof(double));
    double eigenvalue;

    // Compute eigenvalues and eigenvectors
    for (int i = 0; i < size; i++) {
        powerIteration(matrix, &eigenvalue, eigenvector, size);

        // Store eigenvalue in D
        for (int j = 0; j < size; j++) {
            D[j][j] = (i == j) ? eigenvalue : 0.0;
        }

        // Store eigenvector in P (column-wise)
        for (int j = 0; j < size; j++) {
            P[j][i] = eigenvector[j];
        }
    }

    free(eigenvector);
}

int main() {
    int size;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    // Allocate memory for matrix, P, and D
    double** matrix = allocateMatrix(size);
    double** P = allocateMatrix(size);
    double** D = allocateMatrix(size);

    printf("Enter the elements of the symmetric matrix row by row:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Diagonalize the matrix
    diagonalizeMatrix(matrix, P, D, size);

    // Output the orthogonal matrix P and diagonal matrix D
    printf("\nOrthogonal Matrix P (Eigenvectors):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.6f ", P[i][j]);
        }
        printf("\n");
    }

    printf("\nDiagonal Matrix D (Eigenvalues):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.6f ", D[i][j]);
        }
        printf("\n");
    }

    // Free memory
    freeMatrix(matrix, size);
    freeMatrix(P, size);
    freeMatrix(D, size);

    return 0;
}
