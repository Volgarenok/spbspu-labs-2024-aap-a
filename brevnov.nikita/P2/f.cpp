#include "brevnov.hpp"
double brevnov::f(const double x, const size_t k, const double error)
{
    double next = x;
    double result = next;
    for (size_t i = 1; i < k; ++i)
    {
        next = (pow(-1,i) * pow(x, 2*i+1) )/ (2*i + 1);
        result +=next;
    }
    if (std::abs(next) - std::abs(atan(x)) > error)
    {
        throw std::logic_error("math-error");
    }
    return result;
}
