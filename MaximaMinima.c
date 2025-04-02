#include <stdio.h>
#include <math.h>

// Define the function f(x, y) (default example)
double f(double x, double y) {
    return x * x + y * y - 4 * x - 6 * y; // Example: f(x, y) = x^2 + y^2 - 4x - 6y
}

// Partial derivatives of f
double f_x(double x, double y) {
    return 2 * x - 4; // Partial derivative with respect to x
}

double f_y(double x, double y) {
    return 2 * y - 6; // Partial derivative with respect to y
}

// Second partial derivatives of f
double f_xx(double x, double y) {
    return 2; // Second partial derivative with respect to x
}

double f_yy(double x, double y) {
    return 2; // Second partial derivative with respect to y
}

double f_xy(double x, double y) {
    return 0; // Mixed partial derivative
}

// Function to compute Hessian determinant
double hessian(double x, double y) {
    return f_xx(x, y) * f_yy(x, y) - f_xy(x, y) * f_xy(x, y);
}

// Unconstrained optimization: Find and classify critical points
void findCriticalPoints(double x_start, double x_end, double y_start, double y_end, double step) {
    printf("\nUnconstrained Optimization:\n");
    printf("Checking for critical points in the region:\n");
    printf("x from %.2f to %.2f, y from %.2f to %.2f\n\n", x_start, x_end, y_start, y_end);

    for (double x = x_start; x <= x_end; x += step) {
        for (double y = y_start; y <= y_end; y += step) {
            if (fabs(f_x(x, y)) < 1e-6 && fabs(f_y(x, y)) < 1e-6) { // Critical point condition
                double hess = hessian(x, y);
                printf("Critical point at (%.2f, %.2f):\n", x, y);
                if (hess > 0 && f_xx(x, y) > 0) {
                    printf("  Local minimum.\n");
                } else if (hess > 0 && f_xx(x, y) < 0) {
                    printf("  Local maximum.\n");
                } else if (hess < 0) {
                    printf("  Saddle point.\n");
                } else {
                    printf("  Indeterminate.\n");
                }
            }
        }
    }
}

// Constrained optimization using Lagrange multipliers
void constrainedOptimization(double x_start, double x_end, double y_start, double y_end, double step, double (*g)(double, double)) {
    printf("\nConstrained Optimization:\n");
    printf("Checking for critical points under the constraint g(x, y) = 0\n");

    for (double x = x_start; x <= x_end; x += step) {
        for (double y = y_start; y <= y_end; y += step) {
            if (fabs(g(x, y)) < 1e-6) { // Constraint condition
                double lagrange_x = f_x(x, y) - 2 * x; // Example ∇f - λ∇g_x
                double lagrange_y = f_y(x, y) - 2 * y; // Example ∇f - λ∇g_y
                if (fabs(lagrange_x) < 1e-6 && fabs(lagrange_y) < 1e-6) {
                    printf("Critical point at (%.2f, %.2f) satisfies the constraint.\n", x, y);
                }
            }
        }
    }
}

// Example constraint function g(x, y)
double g(double x, double y) {
    return x * x + y * y - 9; // Example: g(x, y) = x^2 + y^2 - 9 (circle of radius 3)
}

int main() {
    double x_start, x_end, y_start, y_end, step;
    int choice;

    printf("Choose an operation:\n");
    printf("1. Unconstrained Optimization\n");
    printf("2. Constrained Optimization\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the region of interest:\n");
    printf("Start of x: ");
    scanf("%lf", &x_start);
    printf("End of x: ");
    scanf("%lf", &x_end);
    printf("Start of y: ");
    scanf("%lf", &y_start);
    printf("End of y: ");
    scanf("%lf", &y_end);

    printf("\nEnter the step size for the search: ");
    scanf("%lf", &step);

    if (choice == 1) {
        // Perform unconstrained optimization
        findCriticalPoints(x_start, x_end, y_start, y_end, step);
    } else if (choice == 2) {
        // Perform constrained optimization
        printf("\nUsing the default constraint: g(x, y) = x^2 + y^2 - 9\n");
        constrainedOptimization(x_start, x_end, y_start, y_end, step, g);
    } else {
        printf("\nInvalid choice. Exiting program.\n");
    }

    return 0;
}
