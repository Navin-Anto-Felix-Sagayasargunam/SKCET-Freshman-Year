#include <stdio.h>
#include <math.h>

// Define the vector-valued function components
double f1(double x, double y) {
    return x * y; // Example: f1(x, y) = x * y
}

double f2(double x, double y) {
    return x + y; // Example: f2(x, y) = x + y
}

// Partial derivative with respect to x
double partialDerivativeX(double (*func)(double, double), double x, double y, double h) {
    return (func(x + h, y) - func(x - h, y)) / (2 * h);
}

// Partial derivative with respect to y
double partialDerivativeY(double (*func)(double, double), double x, double y, double h) {
    return (func(x, y + h) - func(x, y - h)) / (2 * h);
}

int main() {
    double x, y, h;

    // Input point (x, y) to calculate Jacobian
    printf("Enter the point (x, y): ");
    scanf("%lf %lf", &x, &y);

    // Input step size for numerical differentiation
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    // Calculate partial derivatives for f1
    double df1_dx = partialDerivativeX(f1, x, y, h);
    double df1_dy = partialDerivativeY(f1, x, y, h);

    // Calculate partial derivatives for f2
    double df2_dx = partialDerivativeX(f2, x, y, h);
    double df2_dy = partialDerivativeY(f2, x, y, h);

    // Output Jacobian matrix
    printf("\nJacobian Matrix at (%.2f, %.2f):\n", x, y);
    printf("[ %.6f  %.6f ]\n", df1_dx, df1_dy);
    printf("[ %.6f  %.6f ]\n", df2_dx, df2_dy);

    return 0;
}
