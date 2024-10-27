#include "header.h"

namespace asafov {
    double f(double x, std::size_t k, double error) {
        double res = 0;
        for (int i = k; i > 0; i--) {
            res = res * x * x / i;
            res = res + ((i % 2 == 0) ? (-1) : (1));
        }
        if (absError(x, k) > error) {
            throw std::logic_error("math-error");
        }
        return res;
    }
}
