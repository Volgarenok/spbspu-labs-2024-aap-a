#include "func.h"
#include <stdexcept>

namespace asafov {
    double expNegPow2x(double x, std::size_t k, double error)
    {
        double result = 0;
        for (std::size_t i = k; i > 0; i--)
        {
            result = result * x * x / i;
            result = result + ((i % 2 == 0) ? (-1) : (1));
        }
        if (absError(x, k) > error)
        {
            throw std::logic_error("math-error");
        }
        return result;
    }
}
