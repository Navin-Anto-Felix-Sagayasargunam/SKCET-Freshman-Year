#include <stdio.h>
#include <math.h>

// Function to check if a point lies on the cone
void checkPointOnCone(double x, double y, double z, double a, double b, double c) {
    double result = (x * x) / (a * a) + (y * y) / (b * b) - (z * z) / (c * c);
    if (fabs(result) < 1e-6) {
        printf("The point (%.2f, %.2f, %.2f) lies ON the cone.\n", x, y, z);
    } else if (result > 0) {
        printf("The point (%.2f, %.2f, %.2f) lies INSIDE the cone.\n", x, y, z);
    } else {
        printf("The point (%.2f, %.2f, %.2f) lies OUTSIDE the cone.\n", x, y, z);
    }
}

// Function to calculate the parametric form coordinates of a cone
void parametricCone(double r, double theta, double k) {
    double x = r * cos(theta);
    double y = r * sin(theta);
    double z = r / k;

    printf("Parametric coordinates: x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
}

int main() {
    double a, b, c; // Parameters of the cone
    double x, y, z; // A point to check

    // Input for the general equation of the cone
    printf("Enter the semi-axes of the base ellipse (a, b) and the height parameter (c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("\nThe general equation of the cone is:\n");
    printf("(x^2)/(%.2f^2) + (y^2)/(%.2f^2) - (z^2)/(%.2f^2) = 0\n\n", a, b, c);

    // Input for a point to check its position relative to the cone
    printf("Enter a point (x, y, z) to check if it lies on the cone: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    checkPointOnCone(x, y, z, a, b, c);

    // Input for parametric form calculation
    double r, theta, k;
    printf("\nEnter the radius of the base (r), angle (theta in radians), and slope parameter (k): ");
    scanf("%lf %lf %lf", &r, &theta, &k);
    parametricCone(r, theta, k);

    return 0;
}
