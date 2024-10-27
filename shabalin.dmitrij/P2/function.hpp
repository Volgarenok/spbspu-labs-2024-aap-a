#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <cstddef>

double f(double x, size_t k, double error);
double stdf(double x);
void output(double x, size_t k, double error, size_t clmn);
void finalOutput(double left, double right, double step, size_t k, double error, size_t clmn);

#endif