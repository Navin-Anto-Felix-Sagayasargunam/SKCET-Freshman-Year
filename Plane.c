#include <stdio.h>
#include <math.h>

// Function to calculate the plane equation from three points
void calculatePlaneFromThreePoints(double x1, double y1, double z1,
                                   double x2, double y2, double z2,
                                   double x3, double y3, double z3,
                                   double* A, double* B, double* C, double* D) {
    *A = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1);
    *B = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1);
    *C = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    *D = -((*A) * x1 + (*B) * y1 + (*C) * z1);
}

// Function to calculate the perpendicular distance from the origin
double calculatePerpendicularFromOrigin(double A, double B, double C, double D) {
    return fabs(D) / sqrt(A * A + B * B + C * C);
}

// Function to calculate perpendicular distance from a point to the plane
double calculatePerpendicularFromPoint(double A, double B, double C, double D,
                                       double x, double y, double z) {
    return fabs(A * x + B * y + C * z + D) / sqrt(A * A + B * B + C * C);
}

// Function to check the position of a point w.r.t. a plane
void checkPositionOfPoint(double A, double B, double C, double D,
                          double x, double y, double z) {
    double value = A * x + B * y + C * z + D;
    if (fabs(value) < 1e-6) {
        printf("The point lies ON the plane.\n");
    } else if (value > 0) {
        printf("The point lies ABOVE the plane.\n");
    } else {
        printf("The point lies BELOW the plane.\n");
    }
}

// Function to calculate the plane through the intersection of two given planes
void calculatePlaneIntersection(double A1, double B1, double C1, double D1,
                                double A2, double B2, double C2, double D2,
                                double k, double* A, double* B, double* C, double* D) {
    *A = A1 + k * A2;
    *B = B1 + k * B2;
    *C = C1 + k * C2;
    *D = D1 + k * D2;
}

int main() {
    double A, B, C, D; // Plane coefficients

    // Three-Point Form of a Plane
    double x1, y1, z1, x2, y2, z2, x3, y3, z3;
    printf("Enter the coordinates of three points (x1, y1, z1), (x2, y2, z2), (x3, y3, z3): ");
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
    calculatePlaneFromThreePoints(x1, y1, z1, x2, y2, z2, x3, y3, z3, &A, &B, &C, &D);
    printf("\nThe equation of the plane is: %.2lfx + %.2lfy + %.2lfz + %.2lf = 0\n", A, B, C, D);

    // Length of perpendicular from the origin
    double perpendicularOrigin = calculatePerpendicularFromOrigin(A, B, C, D);
    printf("\nLength of perpendicular from the origin to the plane: %.6lf\n", perpendicularOrigin);

    // Length of perpendicular from a point
    double px, py, pz;
    printf("\nEnter the coordinates of a point (px, py, pz): ");
    scanf("%lf %lf %lf", &px, &py, &pz);
    double perpendicularPoint = calculatePerpendicularFromPoint(A, B, C, D, px, py, pz);
    printf("Length of perpendicular from the point to the plane: %.6lf\n", perpendicularPoint);

    // Position of a point w.r.t. the plane
    checkPositionOfPoint(A, B, C, D, px, py, pz);

    // Plane through the intersection of two given planes
    double A1, B1, C1, D1, A2, B2, C2, D2, k;
    printf("\nEnter the coefficients of the first plane (A1, B1, C1, D1): ");
    scanf("%lf %lf %lf %lf", &A1, &B1, &C1, &D1);
    printf("Enter the coefficients of the second plane (A2, B2, C2, D2): ");
    scanf("%lf %lf %lf %lf", &A2, &B2, &C2, &D2);
    printf("Enter the value of k (parameter for intersection): ");
    scanf("%lf", &k);

    double Ai, Bi, Ci, Di;
    calculatePlaneIntersection(A1, B1, C1, D1, A2, B2, C2, D2, k, &Ai, &Bi, &Ci, &Di);
    printf("\nThe equation of the plane through the intersection is: %.2lfx + %.2lfy + %.2lfz + %.2lf = 0\n", Ai, Bi, Ci, Di);

    return 0;
}
