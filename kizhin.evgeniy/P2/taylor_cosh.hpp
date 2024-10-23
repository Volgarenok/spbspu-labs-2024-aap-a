#ifndef TAYLOR_COSH_HPP
#define TAYLOR_COSH_HPP

#include <cstddef>

namespace kizhin
{

double computeTaylorCosh(double argument, size_t maxOperands,
                         double absoluteError);
}

#endif
