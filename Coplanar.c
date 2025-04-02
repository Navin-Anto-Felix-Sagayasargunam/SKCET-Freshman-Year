#include <stdio.h>
#include <math.h>

// Function to calculate direction ratios of a line passing through two points
void calculateDirectionRatios(double x1, double y1, double z1,
                               double x2, double y2, double z2,
                               double* dx, double* dy, double* dz) {
    *dx = x2 - x1;
    *dy = y2 - y1;
    *dz = z2 - z1;
}

// Function to compute the scalar triple product of three vectors
double scalarTripleProduct(double dx1, double dy1, double dz1,
                           double dx2, double dy2, double dz2,
                           double dx3, double dy3, double dz3) {
    return dx1 * (dy2 * dz3 - dz2 * dy3) -
           dy1 * (dx2 * dz3 - dz2 * dx3) +
           dz1 * (dx2 * dy3 - dy2 * dx3);
}

int main() {
    double x1, y1, z1, x2, y2, z2;       // First line points
    double x3, y3, z3, x4, y4, z4;       // Second line points
    double x5, y5, z5;                   // Point from the third line

    double dx1, dy1, dz1;                // Direction ratios of the first line
    double dx2, dy2, dz2;                // Direction ratios of the second line
    double dx3, dy3, dz3;                // Vector connecting the third point to a point on the first line

    // Input for the first line
    printf("Enter the coordinates of two points on the first line (x1, y1, z1) and (x2, y2, z2): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
    calculateDirectionRatios(x1, y1, z1, x2, y2, z2, &dx1, &dy1, &dz1);

    // Input for the second line
    printf("Enter the coordinates of two points on the second line (x3, y3, z3) and (x4, y4, z4): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x3, &y3, &z3, &x4, &y4, &z4);
    calculateDirectionRatios(x3, y3, z3, x4, y4, z4, &dx2, &dy2, &dz2);

    // Input for a point from the third line
    printf("Enter the coordinates of a point on the third line (x5, y5, z5): ");
    scanf("%lf %lf %lf", &x5, &y5, &z5);
    calculateDirectionRatios(x1, y1, z1, x5, y5, z5, &dx3, &dy3, &dz3);

    // Check coplanarity using scalar triple product
    double tripleProduct = scalarTripleProduct(dx1, dy1, dz1, dx2, dy2, dz2, dx3, dy3, dz3);

    printf("\nScalar Triple Product: %.6f\n", tripleProduct);
    if (fabs(tripleProduct) < 1e-6) {
        printf("The lines are coplanar.\n");
    } else {
        printf("The lines are NOT coplanar.\n");
    }

    return 0;
}
