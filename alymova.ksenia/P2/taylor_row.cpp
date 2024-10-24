#include "funcs.h"
#include <stdexcept>
double alymova::taylor_row(double x, size_t k, const double error)
{
    double summ = x;
    double next = x;
    int denom = 3;
    for (size_t i = 1; i <= k; i++)
    {
        next = next * x * x / denom;
        summ += next;
        denom += 2;
    }
    if (next > error)
    {
        throw std::logic_error("math error");
    }
    else
    {
        return summ;
    }
}