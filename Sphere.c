#include <stdio.h>
#include <math.h>

// Function to calculate the equation of a sphere
void sphereEquation(double h, double k, double l, double r) {
    printf("The equation of the sphere is: \n");
    printf("(x - %.2f)^2 + (y - %.2f)^2 + (z - %.2f)^2 = %.2f\n\n", h, k, l, r * r);
}

// Function to calculate the equation of a tangent plane to the sphere at a given point
void tangentPlane(double h, double k, double l, double r, double x1, double y1, double z1) {
    if (fabs((x1 - h) * (x1 - h) + (y1 - k) * (y1 - k) + (z1 - l) * (z1 - l) - r * r) > 1e-6) {
        printf("The point (%.2f, %.2f, %.2f) is not on the sphere.\n", x1, y1, z1);
        return;
    }

    printf("The equation of the tangent plane at (%.2f, %.2f, %.2f) is: \n", x1, y1, z1);
    printf("%.2f(x - %.2f) + %.2f(y - %.2f) + %.2f(z - %.2f) = 0\n\n",
           2 * (x1 - h), x1, 2 * (y1 - k), y1, 2 * (z1 - l), z1);
}

// Function to calculate the plane section of the sphere (intersection with a plane)
void planeSection(double h, double k, double l, double r, double A, double B, double C, double D) {
    // Distance from the center of the sphere to the plane
    double d = fabs(A * h + B * k + C * l + D) / sqrt(A * A + B * B + C * C);

    if (d > r) {
        printf("The plane does not intersect the sphere.\n");
        return;
    }

    double radiusOfCircle = sqrt(r * r - d * d);

    printf("The plane intersects the sphere, forming a circle.\n");
    printf("The radius of the circle is: %.2f\n\n", radiusOfCircle);
}

// Function to calculate the equation of a sphere passing through a circle
void sphereThroughCircle(double h, double k, double l, double r,
                         double A, double B, double C, double D) {
    printf("The general equation of a sphere passing through the circle is: \n");
    printf("(x - %.2f)^2 + (y - %.2f)^2 + (z - %.2f)^2 = %.2f - λ(%.2f*x + %.2f*y + %.2f*z + %.2f)\n\n",
           h, k, l, r * r, A, B, C, D);
}

int main() {
    // Input the sphere's center and radius
    double h, k, l, r;
    printf("Enter the center of the sphere (h, k, l): ");
    scanf("%lf %lf %lf", &h, &k, &l);
    printf("Enter the radius of the sphere (r): ");
    scanf("%lf", &r);

    // Output the equation of the sphere
    sphereEquation(h, k, l, r);

    // Input a point to find the tangent plane
    double x1, y1, z1;
    printf("Enter a point on the sphere to find the tangent plane (x1, y1, z1): ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);
    tangentPlane(h, k, l, r, x1, y1, z1);

    // Input a plane to find the plane section of the sphere
    double A, B, C, D;
    printf("Enter the coefficients of the plane (Ax + By + Cz + D = 0): ");
    scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
    planeSection(h, k, l, r, A, B, C, D);

    // Output the equation of a sphere passing through the circle
    sphereThroughCircle(h, k, l, r, A, B, C, D);

    return 0;
}
