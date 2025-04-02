#include <stdio.h>
#include <math.h>

// Define the objective function f(x, y)
double f(double x, double y) {
    return x * y; // Example: f(x, y) = x * y
}

// Define the constraint function g(x, y) = x^2 + y^2 - 9
double g(double x, double y) {
    return x * x + y * y - 9; // Example: g(x, y) = x^2 + y^2 - 9
}

// Partial derivatives of the Lagrange function L(x, y, lambda)
double L_x(double x, double y, double lambda) {
    return y + lambda * 2 * x; // ∂L/∂x = ∂f/∂x + λ * ∂g/∂x
}

double L_y(double x, double y, double lambda) {
    return x + lambda * 2 * y; // ∂L/∂y = ∂f/∂y + λ * ∂g/∂y
}

double L_lambda(double x, double y) {
    return g(x, y); // ∂L/∂λ = g(x, y)
}

// Function to solve the system of equations
void lagrangeMethod(double x_start, double x_end, double y_start, double y_end, double lambda_start, double lambda_end, double step) {
    printf("\nSolving optimization problem using Lagrange multipliers:\n");
    printf("Objective function: f(x, y) = x * y\n");
    printf("Constraint: g(x, y) = x^2 + y^2 - 9\n");
    printf("Searching in the region x: [%.2f, %.2f], y: [%.2f, %.2f], λ: [%.2f, %.2f]\n\n",
           x_start, x_end, y_start, y_end, lambda_start, lambda_end);

    for (double x = x_start; x <= x_end; x += step) {
        for (double y = y_start; y <= y_end; y += step) {
            for (double lambda = lambda_start; lambda <= lambda_end; lambda += step) {
                if (fabs(L_x(x, y, lambda)) < 1e-6 &&
                    fabs(L_y(x, y, lambda)) < 1e-6 &&
                    fabs(L_lambda(x, y)) < 1e-6) {
                    printf("Critical point: x = %.2f, y = %.2f, λ = %.2f\n", x, y, lambda);
                }
            }
        }
    }
}

int main() {
    // Input region and step size for the search
    double x_start, x_end, y_start, y_end, lambda_start, lambda_end, step;

    printf("Enter the search region for x (start, end): ");
    scanf("%lf %lf", &x_start, &x_end);
    printf("Enter the search region for y (start, end): ");
    scanf("%lf %lf", &y_start, &y_end);
    printf("Enter the search region for λ (start, end): ");
    scanf("%lf %lf", &lambda_start, &lambda_end);
    printf("Enter the step size for the search: ");
    scanf("%lf", &step);

    // Solve using Lagrange multipliers
    lagrangeMethod(x_start, x_end, y_start, y_end, lambda_start, lambda_end, step);

    return 0;
}
