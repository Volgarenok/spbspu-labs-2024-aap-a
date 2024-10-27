#ifndef BREVNOV_HPP
#define BREVNOV_HPP
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
namespace brevnov{
    double f(double x, size_t k, double error);
    void output(const double left, const double right, const size_t k);
} 
#endif