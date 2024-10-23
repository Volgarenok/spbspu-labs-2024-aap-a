#ifndef OUTRES_HPP
#define OUTRES_HPP
#include <cstddef>
namespace dribas
{
  void outall(double x, size_t koll, double error);
  void outline(double left, double right, double step, size_t koll, double error);
}
#endif
