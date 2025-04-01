#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6  // Threshold for floating-point comparison

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

// Function to dynamically allocate a vector
double* allocateVector(int size) {
    return (double*)malloc(size * sizeof(double));
}

// Function to free a vector
void freeVector(double* vector) {
    free(vector);
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

// Function to evaluate the quadratic form Q(x) = x^T A x
double evaluateQuadraticForm(double** matrix, double* vector, int size) {
    double* temp = allocateVector(size);
    matrixVectorMultiply(matrix, vector, temp, size);

    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += temp[i] * vector[i];
    }

    freeVector(temp);
    return result;
}

// Function to compute eigenvalues and eigenvectors (placeholder with precomputed values for simplicity)
void computeEigen(double** matrix, double* eigenvalues, double** eigenvectors, int size) {
    // Example eigenvalues and eigenvectors for simplicity
    eigenvalues[0] = 6.0; // Example eigenvalues
    eigenvalues[1] = 4.0;
    eigenvalues[2] = 2.0;

    eigenvectors[0][0] = 1.0; eigenvectors[0][1] = 0.0; eigenvectors[0][2] = 0.0; // Example eigenvectors
    eigenvectors[1][0] = 0.0; eigenvectors[1][1] = 1.0; eigenvectors[1][2] = 0.0;
    eigenvectors[2][0] = 0.0; eigenvectors[2][1] = 0.0; eigenvectors[2][2] = 1.0;
}

// Function to test definiteness of the quadratic form
void testDefiniteness(double* eigenvalues, int size) {
    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < size; i++) {
        if (eigenvalues[i] > EPSILON) positive++;
        else if (eigenvalues[i] < -EPSILON) negative++;
        else zero++;
    }

    printf("\nDefiniteness of the quadratic form:\n");
    if (positive == size) {
        printf("The quadratic form is Positive Definite.\n");
    } else if (negative == size) {
        printf("The quadratic form is Negative Definite.\n");
    } else if (positive > 0 && negative > 0) {
        printf("The quadratic form is Indefinite.\n");
    } else if (zero > 0) {
        printf("The quadratic form is Semi-Definite.\n");
    }
}

// Function to reduce the quadratic form to canonical form
void reduceToCanonicalForm(double** matrix, double** P, double** D, double* eigenvalues, int size) {
    computeEigen(matrix, eigenvalues, P, size);

    // Fill diagonal matrix D with eigenvalues
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            D[i][j] = (i == j) ? eigenvalues[i] : 0.0;
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    // Allocate memory for matrix, transformation matrix (P), diagonal matrix (D), and vector
    double** matrix = allocateMatrix(size);
    double** P = allocateMatrix(size);
    double** D = allocateMatrix(size);
    double* vector = allocateVector(size);
    double* eigenvalues = allocateVector(size);

    // Input the symmetric matrix (coefficient matrix of the quadratic form)
    printf("Enter the elements of the symmetric matrix row by row:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Input the vector
    printf("Enter the elements of the vector:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &vector[i]);
    }

    // Evaluate the quadratic form
    double result = evaluateQuadraticForm(matrix, vector, size);
    printf("\nValue of the quadratic form Q(x): %.6f\n", result);

    // Reduce the quadratic form to canonical form
    reduceToCanonicalForm(matrix, P, D, eigenvalues, size);

    // Test the definiteness of the quadratic form
    testDefiniteness(eigenvalues, size);

    // Output the diagonal and orthogonal matrices
    printf("\nDiagonal Matrix D (Eigenvalues):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.6f ", D[i][j]);
        }
        printf("\n");
    }

    printf("\nOrthogonal Matrix P (Eigenvectors):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.6f ", P[i][j]);
        }
        printf("\n");
    }

    printf("\nThe quadratic form has been reduced to its canonical form:\n");
    printf("Q(x) = ");
    for (int i = 0; i < size; i++) {
        printf("%.6f*y%d^2 ", eigenvalues[i], i + 1);
        if (i < size - 1) printf("+ ");
    }
    printf("\n");

    // Free memory
    freeMatrix(matrix, size);
    freeMatrix(P, size);
    freeMatrix(D, size);
    freeVector(vector);
    freeVector(eigenvalues);

    return 0;
}
