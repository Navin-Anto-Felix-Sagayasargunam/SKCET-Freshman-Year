#include <stdio.h>
#include <math.h>

// Function to calculate magnitude of a vector
double calculateMagnitude(double dx, double dy, double dz) {
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to calculate direction cosines from direction ratios
void calculateDirectionCosines(double dx, double dy, double dz, double* l, double* m, double* n) {
    double magnitude = calculateMagnitude(dx, dy, dz);

    if (magnitude == 0) {
        printf("Invalid direction ratios (all zero values).\n");
        *l = *m = *n = 0;
        return;
    }

    *l = dx / magnitude; // Direction cosine along x-axis
    *m = dy / magnitude; // Direction cosine along y-axis
    *n = dz / magnitude; // Direction cosine along z-axis
}

// Function to verify the relation among direction cosines
void verifyDirectionCosineRelation(double l, double m, double n) {
    double sum = l * l + m * m + n * n;
    printf("\nRelation among direction cosines:\n");
    printf("l^2 + m^2 + n^2 = %.6f\n", sum);

    if (fabs(sum - 1.0) < 1e-6) {
        printf("The relation is satisfied (l^2 + m^2 + n^2 = 1).\n");
    } else {
        printf("The relation is NOT satisfied.\n");
    }
}

int main() {
    double dx, dy, dz; // Direction ratios
    double l, m, n;    // Direction cosines

    printf("Enter the direction ratios (dx, dy, dz) of the line: ");
    scanf("%lf %lf %lf", &dx, &dy, &dz);

    // Calculate direction cosines
    calculateDirectionCosines(dx, dy, dz, &l, &m, &n);

    // Output direction cosines
    printf("\nDirection Cosines:\n");
    printf("l = %.6f\n", l);
    printf("m = %.6f\n", m);
    printf("n = %.6f\n", n);

    // Verify relation among direction cosines
    verifyDirectionCosineRelation(l, m, n);

    return 0;
}
