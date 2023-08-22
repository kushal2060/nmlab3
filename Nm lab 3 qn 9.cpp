#include <iostream>
#include <cmath>

double func(double x, double y) {
    return x * y;  // Replace this with your desired function of two variables
}

double double_integration_trapezoidal(double (*func)(double, double), 
                                     double x0, double x1, 
                                     double y0, double y1, 
                                     int nx, int ny) {
    double hx = (x1 - x0) / nx;
    double hy = (y1 - y0) / ny;

    double integral = 0.0;

    for (int i = 0; i <= nx; ++i) {
        for (int j = 0; j <= ny; ++j) {
            double x = x0 + i * hx;
            double y = y0 + j * hy;

            double weight = 1.0;

            // Modify the weight for corner points
            if (i == 0 || i == nx) {
                weight *= 0.5;
            }
            if (j == 0 || j == ny) {
                weight *= 0.5;
            }

            integral += weight * func(x, y);
        }
    }

    return hx * hy * integral;
}

int main() {
    double x0 = 0.0;   // Lower x limit
    double x1 = 1.0;   // Upper x limit
    double y0 = 0.0;   // Lower y limit
    double y1 = 2.0;   // Upper y limit
    int nx = 100;      // Number of subintervals in x direction
    int ny = 100;      // Number of subintervals in y direction

    double result = double_integration_trapezoidal(func, x0, x1, y0, y1, nx, ny);
    std::cout << "Estimated double integral: " << result << std::endl;

    return 0;
}
