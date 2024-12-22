#include "output.hpp"
#include "taylor.hpp"

namespace beshimow
{
    void rowOutput(double x, size_t k, double error)
    {
        double result = taylor(x, k, error);
        std::cout << "x: " << x << ", Taylor series approximation: " << result;
    }
}
