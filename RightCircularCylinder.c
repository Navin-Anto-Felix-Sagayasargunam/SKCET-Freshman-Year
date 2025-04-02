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

int main() {
    int choice;
    printf("Choose the orientation of the cylinder:\n");
    printf("1. Symmetric about the z-axis\n");
    printf("2. Symmetric about the x-axis\n");
    printf("3. Symmetric about the y-axis\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    double r, x, y, z;
    printf("\nEnter the radius of the cylinder (r): ");
    scanf("%lf", &r);

    if (choice == 1) {
        // Cylinder symmetric about the z-axis
        printf("The equation of the cylinder is: x^2 + y^2 = %.2f\n", r * r);
    } else if (choice == 2) {
        // Cylinder symmetric about the x-axis
        printf("The equation of the cylinder is: y^2 + z^2 = %.2f\n", r * r);
    } else if (choice == 3) {
        // Cylinder symmetric about the y-axis
        printf("The equation of the cylinder is: x^2 + z^2 = %.2f\n", r * r);
    } else {
        printf("Invalid choice. Please run the program again.\n");
        return 0;
    }

    // Check a point's position relative to the cylinder
    printf("\nEnter the coordinates of a point (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);
    if (choice == 1) {
        checkPointOnRightCircularCylinder(x, y, z, r);
    } else if (choice == 2) {
        checkPointOnRightCircularCylinder(y, z, x, r); // Swap x, y, z for x-axis symmetry
    } else if (choice == 3) {
        checkPointOnRightCircularCylinder(x, z, y, r); // Swap x, y, z for y-axis symmetry
    }

    return 0;
}
