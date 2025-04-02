#include <stdio.h>
#include <math.h>

// Function representing the curve y = f(x)
double curveFunction(double x) {
    return x * x; // Example: y = x^2
}

// Function to compute the first and second derivatives
void calculateDerivatives(double (*f)(double), double x, double h, double* dy_dx, double* d2y_dx2) {
    *dy_dx = (f(x + h) - f(x - h)) / (2 * h); // First derivative
    *d2y_dx2 = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h); // Second derivative
}

// Function to calculate the evolute (center of curvature)
void calculateEvolute(double x, double y, double dy_dx, double d2y_dx2, double* xe, double* ye) {
    double normal_length = pow(1 + dy_dx * dy_dx, 0.5) / fabs(d2y_dx2);

    // Coordinates of the evolute
    *xe = x - dy_dx * normal_length;
    *ye = y + normal_length;
}

int main() {
    double x, h; // Input x-value and step size
    double x_start, x_end, step;

    // Input range and step size for calculating the evolute
    printf("Enter the range for x (start, end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter the step size for x: ");
    scanf("%lf", &step);
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    printf("\nEvolute Points (approximated numerically):\n");
    printf("x_evolute\t\ty_evolute\n");

    for (x = x_start; x <= x_end; x += step) {
        double y = curveFunction(x);
        double dy_dx, d2y_dx2;

        // Calculate derivatives
        calculateDerivatives(curveFunction, x, h, &dy_dx, &d2y_dx2);

        // Skip points where the second derivative is zero
        if (fabs(d2y_dx2) < 1e-6) {
            continue;
        }

        // Calculate evolute coordinates
        double xe, ye;
        calculateEvolute(x, y, dy_dx, d2y_dx2, &xe, &ye);

        // Output evolute point
        printf("%.6f\t\t%.6f\n", xe, ye);
    }

    return 0;
}
