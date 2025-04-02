#include <stdio.h>
#include <math.h>

// Function to calculate the cross product of two vectors
void crossProduct(double dx1, double dy1, double dz1,
                  double dx2, double dy2, double dz2,
                  double* cx, double* cy, double* cz) {
    *cx = dy1 * dz2 - dz1 * dy2;
    *cy = dz1 * dx2 - dx1 * dz2;
    *cz = dx1 * dy2 - dy1 * dx2;
}

// Function to calculate the dot product of two vectors
double dotProduct(double dx1, double dy1, double dz1,
                  double dx2, double dy2, double dz2) {
    return dx1 * dx2 + dy1 * dy2 + dz1 * dz2;
}

// Function to calculate the magnitude of a vector
double magnitude(double dx, double dy, double dz) {
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to calculate the shortest distance between two skew lines
double shortestDistance(double x1, double y1, double z1, double dx1, double dy1, double dz1,
                        double x2, double y2, double z2, double dx2, double dy2, double dz2) {
    double cx, cy, cz; // Cross product of direction vectors
    crossProduct(dx1, dy1, dz1, dx2, dy2, dz2, &cx, &cy, &cz);

    double magCross = magnitude(cx, cy, cz);

    if (fabs(magCross) < 1e-6) {
        printf("The lines are parallel, so the shortest distance cannot be determined using this method.\n");
        return 0.0;
    }

    // Vector connecting a point from Line 1 to a point from Line 2
    double px = x2 - x1;
    double py = y2 - y1;
    double pz = z2 - z1;

    // Dot product of (a2 - a1) with the cross product of d1 and d2
    double dot = dotProduct(px, py, pz, cx, cy, cz);

    // Calculate and return the shortest distance
    return fabs(dot) / magCross;
}

int main() {
    // Input for Line 1
    double x1, y1, z1, dx1, dy1, dz1;
    printf("Enter a point on the first line (x1, y1, z1): ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);
    printf("Enter the direction ratios of the first line (dx1, dy1, dz1): ");
    scanf("%lf %lf %lf", &dx1, &dy1, &dz1);

    // Input for Line 2
    double x2, y2, z2, dx2, dy2, dz2;
    printf("Enter a point on the second line (x2, y2, z2): ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);
    printf("Enter the direction ratios of the second line (dx2, dy2, dz2): ");
    scanf("%lf %lf %lf", &dx2, &dy2, &dz2);

    // Calculate the shortest distance
    double distance = shortestDistance(x1, y1, z1, dx1, dy1, dz1, x2, y2, z2, dx2, dy2, dz2);

    if (distance > 0.0) {
        printf("\nThe shortest distance between the two skew lines is: %.6f\n", distance);
    }

    return 0;
}
