#include <stdio.h>
#include <math.h>

// Example function f(x, y) = x^2 + y^2 + xy
double function(double x, double y) {
    return x * x + y * y + x * y; // f(x, y) = x^2 + y^2 + xy
}

// Partial derivative with respect to x
double partialDerivativeX(double x, double y, double h) {
    return (function(x + h, y) - function(x - h, y)) / (2 * h);
}

// Partial derivative with respect to y
double partialDerivativeY(double x, double y, double h) {
    return (function(x, y + h) - function(x, y - h)) / (2 * h);
}

// Second partial derivative with respect to x
double secondPartialDerivativeX(double x, double y, double h) {
    return (function(x + h, y) - 2 * function(x, y) + function(x - h, y)) / (h * h);
}

// Second partial derivative with respect to y
double secondPartialDerivativeY(double x, double y, double h) {
    return (function(x, y + h) - 2 * function(x, y) + function(x, y - h)) / (h * h);
}

// Mixed partial derivative with respect to x and y
double mixedPartialDerivativeXY(double x, double y, double h) {
    return (function(x + h, y + h) - function(x + h, y - h) - function(x - h, y + h) + function(x - h, y - h)) / (4 * h * h);
}

int main() {
    double x0, y0, x, y, h;

    // Input expansion point (x0, y0)
    printf("Enter the expansion point (x0, y0): ");
    scanf("%lf %lf", &x0, &y0);

    // Input point to approximate (x, y)
    printf("Enter the point to approximate (x, y): ");
    scanf("%lf %lf", &x, &y);

    // Input step size for numerical differentiation
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    // Calculate partial derivatives
    double f0 = function(x0, y0);
    double fx = partialDerivativeX(x0, y0, h);
    double fy = partialDerivativeY(x0, y0, h);
    double fxx = secondPartialDerivativeX(x0, y0, h);
    double fyy = secondPartialDerivativeY(x0, y0, h);
    double fxy = mixedPartialDerivativeXY(x0, y0, h);

    // Calculate Taylor series expansion
    double dx = x - x0;
    double dy = y - y0;
    double approximation = f0 + fx * dx + fy * dy
        + 0.5 * (fxx * dx * dx + 2 * fxy * dx * dy + fyy * dy * dy);

    // Output results
    printf("\nResults of Taylor Series Expansion:\n");
    printf("f(x0, y0) = %.6f\n", f0);
    printf("fx = %.6f, fy = %.6f\n", fx, fy);
    printf("fxx = %.6f, fyy = %.6f, fxy = %.6f\n", fxx, fyy, fxy);
    printf("Taylor Series Approximation at (%.2f, %.2f): %.6f\n", x, y, approximation);

    return 0;
}
