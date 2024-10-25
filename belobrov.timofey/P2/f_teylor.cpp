#include "f_teylor.hpp"
#include <cmath>
#include <stdexcept>
using namespace belobrov;

double f_taylor(const double& x, const size_t& k)
{
    const double error = 0.001;
    const double step = 0.05;
    double teylor_result = x;
    double z = -1;
    double d_x = x;  

    for (int n = 1; n < k; ++n) {
        d_x *= x * x;  
        double coefficient = z / (2 * n * (2 * n + 1));
        teylor_result += coefficient * d_x;
        z *= -1; 
    }

    double ln_result = log(x + sqrt(x * x + 1));


    if (std::abs(teylor_result-ln_result) > error)
    {
    throw std::logic_error("<MATH ERROR>");
    }

    return teylor_result;

}
