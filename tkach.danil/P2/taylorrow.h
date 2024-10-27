#ifndef TAYLORROW_H
#define TAYLORROW_H
#include <cstddef>

namespace tkach
{
  double coshTaylor(double start, size_t maxkolvo, double error);
  double stdCosh(double coshx);
}

#endif
