#include <stdio.h>
#include <math.h>

// Define the function f(x, y, z) in terms of r, theta, and z
double f(double r, double theta, double z) {
    return r * cos(theta) + r * sin(theta) + z; // Example: f(x, y, z) = x + y + z, transformed to cylindrical
}

// Compute the integral in cylindrical coordinates
double integrateCylindrical(double r_start, double r_end, double theta_start, double theta_end, double z_start, double z_end, int nr, int ntheta, int nz) {
    double hr = (r_end - r_start) / nr;          // Step size for r
    double htheta = (theta_end - theta_start) / ntheta; // Step size for theta
    double hz = (z_end - z_start) / nz;          // Step size for z
    double sum = 0.0;

    for (int i = 0; i <= nr; i++) {
        double r = r_start + i * hr;
        for (int j = 0; j <= ntheta; j++) {
            double theta = theta_start + j * htheta;
            for (int k = 0; k <= nz; k++) {
                double z = z_start + k * hz;
                double weight = 1.0;

                // Apply trapezoidal rule weights
                if (i == 0 || i == nr) weight *= 0.5;
                if (j == 0 || j == ntheta) weight *= 0.5;
                if (k == 0 || k == nz) weight *= 0.5;

                // Add the contribution of the current point
                sum += weight * f(r, theta, z) * r;
            }
        }
    }

    return sum * hr * htheta * hz;
}

int main() {
    int nr, ntheta, nz;
    double r_start, r_end, theta_start, theta_end, z_start, z_end;

    // Input bounds and intervals
    printf("Triple Integral with Change of Variables (Cartesian to Cylindrical):\n");
    printf("Enter r range (start and end): ");
    scanf("%lf %lf", &r_start, &r_end);
    printf("Enter theta range (start and end in radians): ");
    scanf("%lf %lf", &theta_start, &theta_end);
    printf("Enter z range (start and end): ");
    scanf("%lf %lf", &z_start, &z_end);
    printf("Enter the number of intervals for r, theta, and z: ");
    scanf("%d %d %d", &nr, &ntheta, &nz);

    double result = integrateCylindrical(r_start, r_end, theta_start, theta_end, z_start, z_end, nr, ntheta, nz);
    printf("Result of the triple integral in cylindrical coordinates: %.6f\n", result);

    return 0;
}
