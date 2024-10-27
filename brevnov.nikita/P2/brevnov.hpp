#ifndef BREVNOV_HPP
#define BREVNOV_HPP
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
namespace brevnov{
    double f(double x, size_t k, double error);
    void output(double left, double right, size_t k);
} 
#endif