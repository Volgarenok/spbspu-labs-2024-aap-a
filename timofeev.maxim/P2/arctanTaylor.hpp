#ifndef ARCTAN_TAYLOR_H
#define ARCTAN_TAYLOR_H

#include <cmath>
#include <stdexcept>

double arctanTaylor(double x, double absError, int numberMax) {
    double term = x;
    double sum = term;
    int n = 0;
    double xPower = x;

    while ((n < numberMax) && (abs(term) >= absError))
    {
        n++;
        xPower *= x * x;
        term = (xPower / (2 * n + 1)) * ((n % 2 == 0) ? 1 : -1);
        sum += term;
    }

    if ((n >= numberMax))
    {
        throw std::logic_error("The maximum number of terms has been exceeded, and the accuracy has not been achieved.");
    }

    return sum;
}
#endif
