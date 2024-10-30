#ifndef OUTRES_HPP
#define OUTRES_HPP
#include <cstddef>

namespace dribas
{
  void outline(double x, size_t count, double error, int sizeclm);
  void outall(double left, double right, double step, size_t count, double error);
}
#endif
