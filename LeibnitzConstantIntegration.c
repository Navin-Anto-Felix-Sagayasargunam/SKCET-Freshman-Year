#include <stdio.h>
#include <math.h>

// Define the function f(x, t)
double f(double x, double t) {
    return x * t + sin(t); // Example: f(x, t) = x * t + sin(t)
}

// Define the partial derivative of f(x, t) with respect to x
double partialDerivativeWithRespectToX(double t) {
    return t; // Partial derivative: ∂f/∂x = t for the example function
}

// Function to compute the integral of g(t) = ∂f/∂x from a to b using the trapezoidal rule
double integral(double a, double b, double x, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        double t = a + i * h;
        double weight = (i == 0 || i == n) ? 0.5 : 1.0; // End points have half weight
        sum += weight * partialDerivativeWithRespectToX(t);
    }
    return sum * h;
}

int main() {
    double a, b, x; // Limits of integration and the value of x
    int n;          // Number of sub-intervals for numerical integration

    // Input values
    printf("Enter the limits of integration (a, b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of sub-intervals for numerical integration (n): ");
    scanf("%d", &n);

    // Compute the derivative of the integral with respect to x
    double result = integral(a, b, x, n);

    // Output the result
    printf("\nThe derivative of the integral with respect to x is: %.6f\n", result);

    return 0;
}
