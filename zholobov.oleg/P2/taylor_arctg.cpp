#include <cstddef>
#include <stdexcept>

static double abs(double x) {
    return (x < 0) ? -x : x;
}

#define M_PI_2   1.57079632679489661923

double taylor_arctg(double x, size_t k, double error) {
    // Since Taylor series works for arctg(x) for abs(x) <= 1
    // If abs(x) > 1, we use formula: arctg(x) = (sign(x) * pi/2 - arctg(1/x)
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
        sum = ((x >= 0) ? M_PI_2 : -M_PI_2) - sum;
    return sum;    
}