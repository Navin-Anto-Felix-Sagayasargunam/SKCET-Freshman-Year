#include <stdio.h>
#include <math.h>

// Functions representing the parametric equations of the curve
double xParam(double t) {
    return t * t; // Example: x = t^2
}

double yParam(double t) {
    return t; // Example: y = t
}

// Function to calculate first and second derivatives numerically
void calculateDerivatives(double (*func)(double), double t, double h, double* first, double* second) {
    *first = (func(t + h) - func(t - h)) / (2 * h); // First derivative
    *second = (func(t + h) - 2 * func(t) + func(t - h)) / (h * h); // Second derivative
}

// Function to calculate radius of curvature
double radiusOfCurvature(double dx_dt, double dy_dt, double d2x_dt2, double d2y_dt2) {
    double numerator = pow(dx_dt * dx_dt + dy_dt * dy_dt, 1.5);
    double denominator = fabs(dx_dt * d2y_dt2 - dy_dt * d2x_dt2);
    return numerator / denominator;
}

int main() {
    double t, h; // Input parameter value and step size
    printf("Enter the value of t (parameter at the point): ");
    scanf("%lf", &t);
    printf("Enter the step size for numerical differentiation (h): ");
    scanf("%lf", &h);

    double dx_dt, dy_dt, d2x_dt2, d2y_dt2;

    // Calculate derivatives for x and y
    calculateDerivatives(xParam, t, h, &dx_dt, &d2x_dt2);
    calculateDerivatives(yParam, t, h, &dy_dt, &d2y_dt2);

    // Calculate radius of curvature
    double R = radiusOfCurvature(dx_dt, dy_dt, d2x_dt2, d2y_dt2);

    // Output results
    printf("\nRadius of Curvature at t = %.2f:\n", t);
    printf("dx/dt = %.6f, d2x/dt2 = %.6f\n", dx_dt, d2x_dt2);
    printf("dy/dt = %.6f, d2y/dt2 = %.6f\n", dy_dt, d2y_dt2);
    printf("Radius of Curvature (R) = %.6f\n", R);

    return 0;
}
