#include <stdio.h>
#include <math.h>

// Function representing the polar curve r = r(θ)
double polarCurve(double theta) {
    return 2 + sin(theta); // Example: r = 2 + sin(θ)
}

// Function to calculate first and second derivatives numerically
void calculateDerivatives(double (*func)(double), double theta, double h, double* dr_dtheta, double* d2r_dtheta2) {
    *dr_dtheta = (func(theta + h) - func(theta - h)) / (2 * h); // First derivative
    *d2r_dtheta2 = (func(theta + h) - 2 * func(theta) + func(theta - h)) / (h * h); // Second derivative
}

// Function to calculate radius of curvature in polar coordinates
double radiusOfCurvaturePolar(double r, double dr_dtheta, double d2r_dtheta2) {
    double numerator = pow(r * r + dr_dtheta * dr_dtheta, 1.5);
    double denominator = fabs(r * r + 2 * dr_dtheta * dr_dtheta - r * d2r_dtheta2);
    return numerator / denominator;
}

int main() {
    double theta, h; // Input angle (in radians) and step size
    printf("Enter the value of θ (in radians): ");
    scanf("%lf", &theta);
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    // Calculate r(θ) and its derivatives
    double r = polarCurve(theta);
    double dr_dtheta, d2r_dtheta2;
    calculateDerivatives(polarCurve, theta, h, &dr_dtheta, &d2r_dtheta2);

    // Calculate radius of curvature
    double R = radiusOfCurvaturePolar(r, dr_dtheta, d2r_dtheta2);

    // Output results
    printf("\nRadius of Curvature at θ = %.2f radians:\n", theta);
    printf("r(θ) = %.6f\n", r);
    printf("dr/dθ = %.6f\n", dr_dtheta);
    printf("d²r/dθ² = %.6f\n", d2r_dtheta2);
    printf("Radius of Curvature (R) = %.6f\n", R);

    return 0;
}
