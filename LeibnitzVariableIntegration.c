#include <stdio.h>
#include <math.h>

// Define the function f(x, t)
double f(double x, double t) {
    return x * t + sin(t); // Example: f(x, t) = x * t + sin(t)
}

// Define the derivative of the upper limit v(x)
double dv_dx(double x) {
    return 1.0; // Example: dv/dx = 1
}

// Define the derivative of the lower limit u(x)
double du_dx(double x) {
    return -1.0; // Example: du/dx = -1
}

// Define the partial derivative of f(x, t) with respect to x
double partialDerivativeWithRespectToX(double t) {
    return t; // Partial derivative: ∂f/∂x = t for the example function
}

// Function to compute the integral of g(t) = ∂f/∂x from u(x) to v(x) using the trapezoidal rule
double integral(double u, double v, double x, int n) {
    double h = (v - u) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        double t = u + i * h;
        double weight = (i == 0 || i == n) ? 0.5 : 1.0; // End points have half weight
        sum += weight * partialDerivativeWithRespectToX(t);
    }
    return sum * h;
}

int main() {
    double x, u, v; // Limits of integration as functions of x and the value of x
    int n;          // Number of sub-intervals for numerical integration

    // Input values
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the lower limit u(x): ");
    scanf("%lf", &u);
    printf("Enter the upper limit v(x): ");
    scanf("%lf", &v);
    printf("Enter the number of sub-intervals for numerical integration (n): ");
    scanf("%d", &n);

    // Compute the derivative of the integral with respect to x
    double f_upper = f(x, v) * dv_dx(x); // f(x, v(x)) * dv/dx
    double f_lower = f(x, u) * du_dx(x); // f(x, u(x)) * du/dx
    double integral_part = integral(u, v, x, n); // Integral of ∂f/∂x

    double result = f_upper - f_lower + integral_part;

    // Output the result
    printf("\nThe derivative of the integral with respect to x is: %.6f\n", result);

    return 0;
}
