#include <stdio.h>
#include <math.h>

// Define the region bounds (example: y = x and y = x^2)
double g1(double x) {
    return x; // Lower bound: y = x
}

double g2(double x) {
    return x * x; // Upper bound: y = x^2
}

// Compute the area using the double integral
double computePlaneArea(double x_start, double x_end, int n, int m) {
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

            sum += weight;
        }
    }
    return sum * hx;
}

int main() {
    int n, m;
    double x_start, x_end;

    // Input bounds and intervals
    printf("Calculate Plane Area using Double Integral:\n");
    printf("Enter x range (start and end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter the number of intervals for x and y: ");
    scanf("%d %d", &n, &m);

    double area = computePlaneArea(x_start, x_end, n, m);
    printf("Area of the plane region: %.6f\n", area);

    return 0;
}
