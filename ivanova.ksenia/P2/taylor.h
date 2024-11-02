#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace ivanova
{
    double f(double x, size_t k, double error);
    double stdf(double x);
}
#endif