#include <iostream>
#include <cmath>
#include "taylor.h"

double ivanova::f(double x, size_t k, double error)
{
    double next = x;
    double result = next;
    for (size_t i = 1; i < k; ++i)
    {
        next *= x;
        result += next;
    }
    if (std::abs(next) > error)
    {
        throw std::logic_error("math-error");
    }
    return result;
}
