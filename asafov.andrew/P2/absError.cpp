#include "header.h"

namespace asafov {
    double absError(double x, std::size_t k) {
        double res = (k % 2 == 0) ? (-1) : (1);
        for (int i = k; i > 0; i--) {
            res = res * x * x / i;;
        }
        return res;
    }
}
