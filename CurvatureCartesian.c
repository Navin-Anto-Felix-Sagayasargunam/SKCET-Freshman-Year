#include <stdio.h>
#include <math.h>

// Function to compute the first and second derivatives
void calculateDerivatives(double (*f)(double), double x, double h, double* dy_dx, double* d2y_dx2) {
    // Using numerical differentiation for dy/dx and d2y/dx2
    *dy_dx = (f(x + h) - f(x - h)) / (2 * h); // First derivative (dy/dx)
    *d2y_dx2 = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h); // Second derivative (d2y/dx2)
}

// Function to compute the radius of curvature
double radiusOfCurvature(double dy_dx, double d2y_dx2) {
    return pow(1 + dy_dx * dy_dx, 1.5) / fabs(d2y_dx2);
}

// Example curve function y = f(x)
double curveFunction(double x) {
    return x * x; // Example: y = x^2
}

int main() {
    double x, h; // Input point and step size
    printf("Enter the value of x (point on the curve): ");
    scanf("%lf", &x);
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    double dy_dx, d2y_dx2;

    // Calculate derivatives at the given point
    calculateDerivatives(curveFunction, x, h, &dy_dx, &d2y_dx2);

    // Calculate radius of curvature
    double R = radiusOfCurvature(dy_dx, d2y_dx2);

    // Output results
    printf("\nRadius of Curvature at x = %.2f:\n", x);
    printf("First derivative (dy/dx) = %.6f\n", dy_dx);
    printf("Second derivative (d2y/dx2) = %.6f\n", d2y_dx2);
    printf("Radius of Curvature (R) = %.6f\n", R);

    return 0;
}
