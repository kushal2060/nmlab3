#include <iostream>
#include <cmath>

double func(double x) {
    return x * x;  // Replace this with your desired function
}

double romberg_integration(double (*func)(double), double a, double b, int n) {
    double R[n+1][n+1] = {0};

    double h = b - a;
    R[0][0] = 0.5 * h * (func(a) + func(b));

    for (int i = 1; i <= n; ++i) {
        h *= 0.5;
        double sum_term = 0.0;
        for (int k = 1; k <= (1 << (i - 1)); ++k) {
            sum_term += func(a + (2 * k - 1) * h);
        }
        R[i][0] = 0.5 * R[i - 1][0] + h * sum_term;

        for (int j = 1; j <= i; ++j) {
            R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / ((1 << (2 * j)) - 1);
        }
    }

    return R[n][n];
}

int main() {
    double a = 0.0;  // Lower limit of integration
    double b = 1.0;  // Upper limit of integration
    int n = 4;       // Number of iterations (increase for higher accuracy)

    double result = romberg_integration(func, a, b, n);
    std::cout << "Estimated integral: " << result << std::endl;

    return 0;
}
