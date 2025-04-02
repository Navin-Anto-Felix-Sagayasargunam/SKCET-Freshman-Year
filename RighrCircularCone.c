#include <stdio.h>
#include <math.h>

// Function to check if a point lies on the right circular cone
void checkPointOnCone(double x, double y, double z, double k) {
    double result = x * x + y * y - k * k * z * z;
    if (fabs(result) < 1e-6) {
        printf("The point (%.2f, %.2f, %.2f) lies ON the cone.\n", x, y, z);
    } else if (result > 0) {
        printf("The point (%.2f, %.2f, %.2f) lies INSIDE the cone.\n", x, y, z);
    } else {
        printf("The point (%.2f, %.2f, %.2f) lies OUTSIDE the cone.\n", x, y, z);
    }
}

// Function to calculate the general equation of a cone with arbitrary axis
void arbitraryAxisCone(double x, double y, double z, double l, double m, double n, double k) {
    double lhs = (l * x + m * y + n * z) * (l * x + m * y + n * z);
    double rhs = k * k * (x * x + y * y + z * z);

    if (fabs(lhs - rhs) < 1e-6) {
        printf("The point lies ON the cone with arbitrary axis.\n");
    } else if (lhs > rhs) {
        printf("The point lies INSIDE the cone with arbitrary axis.\n");
    } else {
        printf("The point lies OUTSIDE the cone with arbitrary axis.\n");
    }
}

int main() {
    // Input for a cone symmetric about the z-axis
    double x, y, z, k;
    printf("Enter the slope parameter (k): ");
    scanf("%lf", &k);
    printf("Enter the coordinates of the point (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    // Check the point's position relative to the cone
    printf("\nCone symmetric about the z-axis:\n");
    printf("Equation: x^2 + y^2 = %.2fz^2\n", k * k);
    checkPointOnCone(x, y, z, k);

    // Input for a cone with arbitrary axis
    double l, m, n;
    printf("\nEnter the axis direction ratios (l, m, n): ");
    scanf("%lf %lf %lf", &l, &m, &n);
    printf("Enter the slope parameter (k): ");
    scanf("%lf", &k);
    arbitraryAxisCone(x, y, z, l, m, n, k);

    return 0;
}
