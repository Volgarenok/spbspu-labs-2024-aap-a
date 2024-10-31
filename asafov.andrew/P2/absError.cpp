#include "func.h"

namespace asafov {
    double absError(double x, std::size_t k)
    {
        double res = (k % 2 == 0) ? (-1) : (1);
        for (std::size_t i = k; i > 0; i--)
        {
            res = res * x * x / i;
        }
        return res;
    }
}
