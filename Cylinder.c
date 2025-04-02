#include <stdio.h>
#include <math.h>

// Function to check if a point lies on a right circular cylinder
void checkPointOnRightCircularCylinder(double x, double y, double z, double r) {
    double result = x * x + y * y - r * r;
    if (fabs(result) < 1e-6) {
        printf("The point (%.2f, %.2f, %.2f) lies ON the cylinder.\n", x, y, z);
    } else if (result > 0) {
        printf("The point (%.2f, %.2f, %.2f) lies OUTSIDE the cylinder.\n", x, y, z);
    } else {
        printf("The point (%.2f, %.2f, %.2f) lies INSIDE the cylinder.\n", x, y, z);
    }
}

// Function to check if a point lies on an elliptic cylinder
void checkPointOnEllipticCylinder(double x, double y, double z, double a, double b) {
    double result = (x * x) / (a * a) + (y * y) / (b * b) - 1;
    if (fabs(result) < 1e-6) {
        printf("The point (%.2f, %.2f, %.2f) lies ON the elliptic cylinder.\n", x, y, z);
    } else if (result > 0) {
        printf("The point (%.2f, %.2f, %.2f) lies OUTSIDE the elliptic cylinder.\n", x, y, z);
    } else {
        printf("The point (%.2f, %.2f, %.2f) lies INSIDE the elliptic cylinder.\n", x, y, z);
    }
}

int main() {
    int choice;
    printf("Choose the type of cylinder:\n");
    printf("1. Right Circular Cylinder\n");
    printf("2. Elliptic Cylinder\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Input for the right circular cylinder
        double r, x, y, z;
        printf("\nEnter the radius of the cylinder (r): ");
        scanf("%lf", &r);
        printf("The equation of the cylinder is: x^2 + y^2 = %.2f\n", r * r);

        // Check a point's position relative to the cylinder
        printf("Enter the coordinates of a point (x, y, z): ");
        scanf("%lf %lf %lf", &x, &y, &z);
        checkPointOnRightCircularCylinder(x, y, z, r);
    } else if (choice == 2) {
        // Input for the elliptic cylinder
        double a, b, x, y, z;
        printf("\nEnter the semi-major axis (a) and semi-minor axis (b) of the ellipse: ");
        scanf("%lf %lf", &a, &b);
        printf("The equation of the cylinder is: (x^2)/(%.2f^2) + (y^2)/(%.2f^2) = 1\n", a, b);

        // Check a point's position relative to the elliptic cylinder
        printf("Enter the coordinates of a point (x, y, z): ");
        scanf("%lf %lf %lf", &x, &y, &z);
        checkPointOnEllipticCylinder(x, y, z, a, b);
    } else {
        printf("Invalid choice. Please run the program again.\n");
    }

    return 0;
}
