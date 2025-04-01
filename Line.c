#include <stdio.h>
#include <math.h>

// Function to calculate direction ratios of the line joining two points
void calculateDirectionRatios(double x1, double y1, double z1, double x2, double y2, double z2, double* dx, double* dy, double* dz) {
    *dx = x2 - x1;
    *dy = y2 - y1;
    *dz = z2 - z1;
}

// Function to calculate magnitude of a vector
double calculateMagnitude(double dx, double dy, double dz) {
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to calculate angle between two lines
double calculateAngleBetweenLines(double dx1, double dy1, double dz1, double dx2, double dy2, double dz2) {
    double dotProduct = dx1 * dx2 + dy1 * dy2 + dz1 * dz2;
    double magnitude1 = calculateMagnitude(dx1, dy1, dz1);
    double magnitude2 = calculateMagnitude(dx2, dy2, dz2);

    if (magnitude1 == 0 || magnitude2 == 0) {
        printf("Invalid direction ratios for one or both lines.\n");
        return -1;
    }

    double cosTheta = dotProduct / (magnitude1 * magnitude2);
    return acos(cosTheta) * (180.0 / M_PI); // Convert to degrees
}

// Function to calculate projection of a line segment on a given line
double calculateProjection(double dx1, double dy1, double dz1, double dx2, double dy2, double dz2) {
    double dotProduct = dx1 * dx2 + dy1 * dy2 + dz1 * dz2;
    double magnitude2 = calculateMagnitude(dx2, dy2, dz2);

    if (magnitude2 == 0) {
        printf("Invalid direction ratios for the given line.\n");
        return -1;
    }

    return dotProduct / magnitude2; // Projection length
}

int main() {
    double x1, y1, z1, x2, y2, z2; // Coordinates of two points
    double dx1, dy1, dz1;          // Direction ratios of the line segment
    double dx2, dy2, dz2;          // Direction ratios of the given line

    // Input for the first line
    printf("Enter the coordinates of the first point (x1, y1, z1): ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);
    printf("Enter the coordinates of the second point (x2, y2, z2): ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);

    // Calculate direction ratios of the line joining two points
    calculateDirectionRatios(x1, y1, z1, x2, y2, z2, &dx1, &dy1, &dz1);
    printf("\nDirection Ratios of the line joining two points:\n");
    printf("dx = %.6f, dy = %.6f, dz = %.6f\n", dx1, dy1, dz1);

    // Input for the second line (given line for angle and projection calculations)
    printf("\nEnter the direction ratios of the given line (dx2, dy2, dz2): ");
    scanf("%lf %lf %lf", &dx2, &dy2, &dz2);

    // Calculate angle between the lines
    double angle = calculateAngleBetweenLines(dx1, dy1, dz1, dx2, dy2, dz2);
    if (angle != -1) {
        printf("\nAngle between the lines: %.6f degrees\n", angle);
    }

    // Calculate projection of the line segment on the given line
    double projection = calculateProjection(dx1, dy1, dz1, dx2, dy2, dz2);
    if (projection != -1) {
        printf("\nProjection of the line segment on the given line: %.6f\n", projection);
    }

    return 0;
}
