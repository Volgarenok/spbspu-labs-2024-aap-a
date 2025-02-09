#include <iostream>
#include <cmath>
#include "output.hpp"
#include "taylor.hpp"

namespace beshimow
{
    void rowOutput(double x, size_t k, double error)
    {
        try {
            double result = taylor(x, k, error);
            std::cout << "x: " << x
                      << ", Taylor series approximation: " << result
                      << ", Standard function value: " << std::sin(x)
                      << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error calculating Taylor series: " << e.what() << std::endl;
        }
    }
}
