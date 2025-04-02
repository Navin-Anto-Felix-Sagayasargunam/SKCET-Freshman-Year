#include <stdio.h>
#include <math.h>

// Define the function f(x, y) to be integrated
double f(double x, double y) {
    return x * x + y * y; // Example: f(x, y) = x^2 + y^2
}

// Define the region of integration: Example (circle of radius 1, centered at the origin)
int region(double x, double y) {
    return (x * x + y * y <= 1); // Returns 1 if (x, y) is in the region, 0 otherwise
}

// Double integral over a specific region using the trapezoidal rule
double doubleIntegralRegion(double x_start, double x_end, double y_start, double y_end, int n, int m) {
    double hx = (x_end - x_start) / n;
    double hy = (y_end - y_start) / m;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            double x = x_start + i * hx;
            double y = y_start + j * hy;

            // Check if the point lies inside the region
            if (region(x, y)) {
                double weight = 1.0;

                if (i == 0 || i == n) weight *= 0.5;
                if (j == 0 || j == m) weight *= 0.5;

                sum += weight * f(x, y);
            }
        }
    }
    return sum * hx * hy;
}

int main() {
    int n, m;
    double x_start, x_end, y_start, y_end;

    // Input bounds and intervals
    printf("Double Integral with Specific Region of Integration:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter y range (start and end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter the number of intervals for x and y: ");
    scanf("%d %d", &n, &m);

    double result = doubleIntegralRegion(x_start, x_end, y_start, y_end, n, m);
    printf("Result of the double integral over the specified region: %.6f\n", result);

    return 0;
}
