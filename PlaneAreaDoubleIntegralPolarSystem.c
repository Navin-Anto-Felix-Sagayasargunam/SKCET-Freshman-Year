#include <stdio.h>
#include <math.h>

// Define the radial bounds of the region
double r1(double theta) {
    return 0; // Example: inner radius r = 0
}

double r2(double theta) {
    return 1; // Example: outer radius r = 1 (circle of radius 1)
}

// Compute the area using the double integral in polar coordinates
double computePolarArea(double theta_start, double theta_end, int n, int m) {
    double h_theta = (theta_end - theta_start) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) {
        double theta = theta_start + i * h_theta;
        double h_r = (r2(theta) - r1(theta)) / m;

        for (int j = 0; j <= m; j++) {
            double r = r1(theta) + j * h_r;
            double weight = 1.0;

            if (i == 0 || i == n) weight *= 0.5;
            if (j == 0 || j == m) weight *= 0.5;

            sum += weight * r;
        }
    }
    return sum * h_theta;
}

int main() {
    int n, m;
    double theta_start, theta_end;

    // Input bounds and intervals
    printf("Calculate Plane Area in Polar Coordinates:\n");
    printf("Enter theta range (start and end in radians): ");
    scanf("%lf %lf", &theta_start, &theta_end);
    printf("Enter the number of intervals for theta and r: ");
    scanf("%d %d", &n, &m);

    double area = computePolarArea(theta_start, theta_end, n, m);
    printf("Area of the plane region: %.6f\n", area);

    return 0;
}
