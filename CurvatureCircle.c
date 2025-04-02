#include <stdio.h>
#include <math.h>

// Function to compute the first and second derivatives
void calculateDerivatives(double (*f)(double), double x, double h, double* dy_dx, double* d2y_dx2) {
    *dy_dx = (f(x + h) - f(x - h)) / (2 * h); // First derivative
    *d2y_dx2 = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h); // Second derivative
}

// Function to compute the radius of curvature
double radiusOfCurvature(double dy_dx, double d2y_dx2) {
    return pow(1 + dy_dx * dy_dx, 1.5) / fabs(d2y_dx2);
}

// Function to calculate the center of curvature
void centerOfCurvature(double x, double y, double dy_dx, double d2y_dx2, double* X_c, double* Y_c) {
    double R = radiusOfCurvature(dy_dx, d2y_dx2); // Radius of curvature
    double normal_length = R / sqrt(1 + dy_dx * dy_dx);

    // Coordinates of the center of curvature
    *X_c = x - dy_dx * normal_length;
    *Y_c = y + normal_length;
}

// Example curve function y = f(x)
double curveFunction(double x) {
    return x * x; // Example: y = x^2
}

int main() {
    double x, y, h; // Input point (x, y) and step size
    printf("Enter the value of x (point on the curve): ");
    scanf("%lf", &x);
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    y = curveFunction(x); // Calculate y at the input x
    double dy_dx, d2y_dx2;

    // Calculate derivatives at the given point
    calculateDerivatives(curveFunction, x, h, &dy_dx, &d2y_dx2);

    // Calculate center of curvature
    double X_c, Y_c;
    centerOfCurvature(x, y, dy_dx, d2y_dx2, &X_c, &Y_c);

    // Calculate radius of curvature
    double R = radiusOfCurvature(dy_dx, d2y_dx2);

    // Output results
    printf("\nResults for the curve at x = %.2f:\n", x);
    printf("First derivative (dy/dx) = %.6f\n", dy_dx);
    printf("Second derivative (d²y/dx²) = %.6f\n", d2y_dx2);
    printf("Radius of Curvature (R) = %.6f\n", R);
    printf("Center of Curvature: (X_c, Y_c) = (%.6f, %.6f)\n", X_c, Y_c);
    printf("Equation of the Circle of Curvature: (X - %.6f)^2 + (Y - %.6f)^2 = %.6f\n", X_c, Y_c, R * R);

    return 0;
}
