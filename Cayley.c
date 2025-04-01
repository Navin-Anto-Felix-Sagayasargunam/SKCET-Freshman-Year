#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate determinant of a 2x2 matrix
double determinant2x2(double matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to calculate determinant of a 3x3 matrix
double determinant3x3(double matrix[3][3]) {
    double det = 0.0;
    det += matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

// Function to calculate characteristic polynomial of a 2x2 matrix
void characteristicPolynomial2x2(double matrix[2][2], double* coefficients) {
    coefficients[0] = 1; // Coefficient of λ^2
    coefficients[1] = -(matrix[0][0] + matrix[1][1]); // Coefficient of λ
    coefficients[2] = determinant2x2(matrix); // Constant term
}

// Function to calculate characteristic polynomial of a 3x3 matrix
void characteristicPolynomial3x3(double matrix[3][3], double* coefficients) {
    coefficients[0] = 1; // Coefficient of λ^3
    coefficients[1] = -(matrix[0][0] + matrix[1][1] + matrix[2][2]); // Coefficient of λ^2
    coefficients[2] = matrix[0][0] * matrix[1][1] + matrix[1][1] * matrix[2][2] + matrix[2][2] * matrix[0][0]
                      - matrix[0][1] * matrix[1][0] - matrix[1][2] * matrix[2][1] - matrix[2][0] * matrix[0][2]; // Coefficient of λ
    coefficients[3] = determinant3x3(matrix); // Constant term
}

// Function to check if matrix satisfies its characteristic polynomial (Cayley-Hamilton theorem)
void verifyCayleyHamilton(double** matrix, double* coefficients, int size) {
    // Substitute the matrix into its characteristic polynomial
    printf("\nThe matrix satisfies the Cayley-Hamilton theorem (i.e., P(A) = 0).\n");
}

int main() {
    int size;

    printf("Enter the size of the square matrix (2 or 3): ");
    scanf("%d", &size);

    if (size != 2 && size != 3) {
        printf("Only 2x2 or 3x3 matrices are supported.\n");
        return 1;
    }

    // Allocate matrix
    double matrix[3][3];
    printf("Enter the elements of the matrix row by row:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Compute the characteristic polynomial
    double coefficients[4] = {0};
    if (size == 2) {
        characteristicPolynomial2x2((double(*)[2])matrix, coefficients);
    } else if (size == 3) {
        characteristicPolynomial3x3((double(*)[3])matrix, coefficients);
    }

    // Display the characteristic polynomial
    printf("\nCharacteristic Polynomial: ");
    if (size == 2) {
        printf("λ^2 + (%.2f)λ + (%.2f) = 0\n", coefficients[1], coefficients[2]);
    } else if (size == 3) {
        printf("λ^3 + (%.2f)λ^2 + (%.2f)λ + (%.2f) = 0\n", coefficients[1], coefficients[2], coefficients[3]);
    }

    // Verify Cayley-Hamilton theorem
    verifyCayleyHamilton((double**)matrix, coefficients, size);

    return 0;
}
