#include <stdio.h>
#include <math.h>

// Define the function to integrate f(x, y)
double f(double x, double y) {
    return x + y; // Example: f(x, y) = x + y
}

// Original order of integration (dy dx)
double integrateOriginalOrder(double x_start, double x_end, double (*g1)(double), double (*g2)(double), int n, int m) {
    double hx = (x_end - x_start) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        double x = x_start + i * hx;
        double hy = (g2(x) - g1(x)) / m;

        for (int j = 0; j <= m; j++) {
            double y = g1(x) + j * hy;
            double weight = 1.0;

            if (i == 0 || i == n) weight *= 0.5;
            if (j == 0 || j == m) weight *= 0.5;

            sum += weight * f(x, y);
        }
    }
    return sum * hx;
}

// Changed order of integration (dx dy)
double integrateChangedOrder(double y_start, double y_end, double (*h1)(double), double (*h2)(double), int n, int m) {
    double hy = (y_end - y_start) / m;
    double sum = 0.0;

    for (int j = 0; j <= m; j++) {
        double y = y_start + j * hy;
        double hx = (h2(y) - h1(y)) / n;

        for (int i = 0; i <= n; i++) {
            double x = h1(y) + i * hx;
            double weight = 1.0;

            if (i == 0 || i == n) weight *= 0.5;
            if (j == 0 || j == m) weight *= 0.5;

            sum += weight * f(x, y);
        }
    }
    return sum * hy;
}

// Define the bounds for the region
double g1(double x) {
    return x; // Example: Lower bound y = x
}

double g2(double x) {
    return 2; // Example: Upper bound y = 2
}

double h1(double y) {
    return 0; // Example: Lower bound x = 0
}

double h2(double y) {
    return y; // Example: Upper bound x = y
}

int main() {
    int n, m;
    double x_start, x_end, y_start, y_end;

    // Input for original order of integration
    printf("Original Order of Integration:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter the number of intervals for x and y: ");
    scanf("%d %d", &n, &m);

    double result_original = integrateOriginalOrder(x_start, x_end, g1, g2, n, m);
    printf("Result of the integral in the original order: %.6f\n\n", result_original);

    // Input for changed order of integration
    printf("Changed Order of Integration:\n");
    printf("Enter y range (start and end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter the number of intervals for x and y: ");
    scanf("%d %d", &n, &m);

    double result_changed = integrateChangedOrder(y_start, y_end, h1, h2, n, m);
    printf("Result of the integral in the changed order: %.6f\n", result_changed);

    return 0;
}
