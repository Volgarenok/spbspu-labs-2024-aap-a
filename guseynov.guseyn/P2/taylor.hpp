#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <cstddef>

namespace guseynov
{
  double calculateUsingTaylorSeries(double x, size_t k, double error);
  void printTableForTaylor(double left, double right, size_t k, double step, double error);
  void printLineForTaylor(double current, size_t k, double error);
}
#endif
