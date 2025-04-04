#include <stdio.h>
#include <math.h>

// Define the function f(x, y) in terms of r and theta
double f(double r, double theta) {
    return r * cos(theta) + r * sin(theta); // Example: f(x, y) = x + y, transformed to polar coordinates
}

// Compute the integral in polar coordinates
double integratePolar(double r_start, double r_end, double theta_start, double theta_end, int nr, int ntheta) {
    double hr = (r_end - r_start) / nr;          // Step size for r
    double htheta = (theta_end - theta_start) / ntheta; // Step size for theta
    double sum = 0.0;

    for (int i = 0; i <= nr; i++) {
        double r = r_start + i * hr;
        for (int j = 0; j <= ntheta; j++) {
            double theta = theta_start + j * htheta;
            double weight = 1.0;

            // Apply trapezoidal rule weights
            if (i == 0 || i == nr) weight *= 0.5;
            if (j == 0 || j == ntheta) weight *= 0.5;

            // Add the contribution of the current point
            sum += weight * f(r, theta) * r;
        }
    }

    return sum * hr * htheta;
}

int main() {
    int nr, ntheta;
    double r_start, r_end, theta_start, theta_end;

    // Input bounds and intervals
    printf("Double Integral with Change of Variables (Cartesian to Polar):\n");
    printf("Enter r range (start and end): ");
    scanf("%lf %lf", &r_start, &r_end);
    printf("Enter theta range (start and end in radians): ");
    scanf("%lf %lf", &theta_start, &theta_end);
    printf("Enter the number of intervals for r and theta: ");
    scanf("%d %d", &nr, &ntheta);

    double result = integratePolar(r_start, r_end, theta_start, theta_end, nr, ntheta);
    printf("Result of the double integral in polar coordinates: %.6f\n", result);

    return 0;
}
