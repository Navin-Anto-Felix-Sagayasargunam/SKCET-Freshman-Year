#include <stdio.h>
#include <math.h>

// Example family of curves: F(x, y, t) = y - t * x + t^2
double F(double x, double y, double t) {
    return y - t * x + t * t;
}

// Partial derivative of F with respect to t
double dF_dt(double x, double y, double t) {
    return -x + 2 * t;
}

// Function to calculate the envelope of the family of curves
void calculateEnvelope(double x, double y, double tStart, double tEnd, double step) {
    double t;
    printf("Envelope points (approximated numerically):\n");
    printf("x\t\ty\n");
    for (t = tStart; t <= tEnd; t += step) {
        double f_val = F(x, y, t);
        double df_dt_val = dF_dt(x, y, t);

        if (fabs(f_val) < 1e-6 && fabs(df_dt_val) < 1e-6) {
            printf("%.6f\t%.6f\n", x, y);
        }
    }
}

int main() {
    double x, y, tStart, tEnd, step;

    // Input values
    printf("Enter the range for the parameter t (start, end): ");
    scanf("%lf %lf", &tStart, &tEnd);
    printf("Enter the step size for parameter t: ");
    scanf("%lf", &step);

    // Loop to approximate the envelope
    calculateEnvelope(x, y, tStart, tEnd, step);

    return 0;
}
