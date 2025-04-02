#include <stdio.h>
#include <math.h>

// Define the function for double integration f(x, y)
double f(double x, double y) {
    return x * x + y * y; // Example: f(x, y) = x^2 + y^2
}

// Define the function for triple integration f(x, y, z)
double f3(double x, double y, double z) {
    return x * y * z; // Example: f(x, y, z) = x * y * z
}

// Double integral using the trapezoidal rule
double doubleIntegral(double x_start, double x_end, double y_start, double y_end, int n, int m) {
    double hx = (x_end - x_start) / n;
    double hy = (y_end - y_start) / m;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            double x = x_start + i * hx;
            double y = y_start + j * hy;
            double weight = 1.0;

            if (i == 0 || i == n) weight *= 0.5;
            if (j == 0 || j == m) weight *= 0.5;

            sum += weight * f(x, y);
        }
    }
    return sum * hx * hy;
}

// Triple integral using the trapezoidal rule
double tripleIntegral(double x_start, double x_end, double y_start, double y_end, double z_start, double z_end, int n, int m, int p) {
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
                double weight = 1.0;

                if (i == 0 || i == n) weight *= 0.5;
                if (j == 0 || j == m) weight *= 0.5;
                if (k == 0 || k == p) weight *= 0.5;

                sum += weight * f3(x, y, z);
            }
        }
    }
    return sum * hx * hy * hz;
}

int main() {
    int n, m, p;
    double x_start, x_end, y_start, y_end, z_start, z_end;

    // Input for double integral
    printf("Double Integral:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter y range (start and end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter the number of intervals for x and y: ");
    scanf("%d %d", &n, &m);
    double result_double = doubleIntegral(x_start, x_end, y_start, y_end, n, m);
    printf("Result of the double integral: %.6f\n\n", result_double);

    // Input for triple integral
    printf("Triple Integral:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter y range (start and end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter z range (start and end): ");
    scanf("%lf %lf", &z_start, &z_end);
    printf("Enter the number of intervals for x, y, and z: ");
    scanf("%d %d %d", &n, &m, &p);
    double result_triple = tripleIntegral(x_start, x_end, y_start, y_end, z_start, z_end, n, m, p);
    printf("Result of the triple integral: %.6f\n", result_triple);

    return 0;
}
