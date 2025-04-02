#include <stdio.h>
#include <math.h>

// Define the function to integrate f(x, y, z)
double f3(double x, double y, double z) {
    return x * y * z; // Example: f(x, y, z) = x * y * z
}

// Define the region for triple integration (sphere of radius 1 centered at the origin)
int region3(double x, double y, double z) {
    return (x * x + y * y + z * z <= 1); // Returns 1 if (x, y, z) is in the region, 0 otherwise
}

// Triple integral over a specific region using the trapezoidal rule
double tripleIntegralRegion(double x_start, double x_end, double y_start, double y_end, double z_start, double z_end, int n, int m, int p) {
    double hx = (x_end - x_start) / n;
    double hy = (y_end - y_start) / m;
    double hz = (z_end - z_start) / p;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= p; k++) {
                double x = x_start + i * hx;
                double y = y_start + j * hy;
                double z = z_start + k * hz;

                // Check if the point lies inside the region
                if (region3(x, y, z)) {
                    double weight = 1.0;

                    if (i == 0 || i == n) weight *= 0.5;
                    if (j == 0 || j == m) weight *= 0.5;
                    if (k == 0 || k == p) weight *= 0.5;

                    sum += weight * f3(x, y, z);
                }
            }
        }
    }
    return sum * hx * hy * hz;
}

int main() {
    int n, m, p;
    double x_start, x_end, y_start, y_end, z_start, z_end;

    // Input bounds and intervals for the triple integral
    printf("Triple Integral with Specific Region of Integration:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter y range (start and end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter z range (start and end): ");
    scanf("%lf %lf", &z_start, &z_end);
    printf("Enter the number of intervals for x, y, and z: ");
    scanf("%d %d %d", &n, &m, &p);

    double result = tripleIntegralRegion(x_start, x_end, y_start, y_end, z_start, z_end, n, m, p);
    printf("Result of the triple integral over the specified region: %.6f\n", result);

    return 0;
}
