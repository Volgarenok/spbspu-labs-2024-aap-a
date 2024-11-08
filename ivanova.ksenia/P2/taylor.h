#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace ivanova
{
    double arctg(double x, size_t k, double error);
    double exp(double x, size_t k, double error);
    double stdArctg(double x);
    double stdExp(double x);
    double factorial(int n);
    void Output(double x, size_t k, double error);
}
#endif