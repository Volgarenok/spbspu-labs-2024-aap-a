#include "brevnov.hpp"
double brevnov::f(double, size_t, double)
{
    throw std::logic_error("math-error");
}
double brevnov::arctg(double)
{
    return 0.0;
}