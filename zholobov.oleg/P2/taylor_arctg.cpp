#include <cstddef>
#include <stdexcept>

static double abs(double x) {
    return (x < 0) ? -x : x;
}

#define M_PI_2   1.57079632679489661923

double taylor_arctg(double x, size_t k, double error) {
    bool argument_less_abs_1 = abs(x) <= 1.0;
    if (!argument_less_abs_1)
        x = 1 / x;
    double sum = x;
    int d = 1;
    double c = x;
    double s = x;
    
    while (k-- > 1) {
        c = -c * x * x;
        d += 2;
        s = c / d;
        if (abs(s) < error) break;
        sum += s;
    }
    if (abs(s) >= error) throw std::runtime_error("Accuracy not reached");

    if (!argument_less_abs_1)
        sum = M_PI_2 - sum;
    return sum;    
}