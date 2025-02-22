#include <cmath>

double arcsinTaylor(double x, size_t n, double error) {
    double term = 0;
    if (n > 10) throw invalid_argument("Maximum iterations exceeded");
    double sum = 0;
    for (size_t i = 0; i < n; ++i) {
        double term = pow(-1, i) * pow(i, 2) / factorial(2 * i + 1) * pow(x, 2 * i + 1);
        sum += term;
        if (fabs(term) < error) break;
    }
    return sum;
}
