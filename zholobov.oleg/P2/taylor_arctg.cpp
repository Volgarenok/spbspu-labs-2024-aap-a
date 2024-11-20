#include "taylor_arctg.hpp"
#include <cstddef>
#include <stdexcept>

namespace {
  constexpr double pi_2 = 1.57079632679489661923;
}

double zholobov::arctg_taylor(double x, size_t k, double error)
{
  // Since Taylor series works for arctg(x) for abs(x) <= 1
  // If abs(x) > 1, we use formula: arctg(x) = (sign(x) * pi/2 - arctg(1/x)
  bool argument_less_abs_1 = std::abs(x) <= 1.0;
  if (!argument_less_abs_1) {
    x = 1 / x;
  }
  double sum = x;
  int d = 1;
  double c = x;
  double s = x;

  while (k-- > 1) {
    c = -c * x * x;
    d += 2;
    s = c / d;
    if (std::abs(s) < error) {
      break;
    }
    sum += s;
  }
  if (std::abs(s) >= error) {
    throw std::runtime_error("Accuracy not reached");
  }

  if (!argument_less_abs_1) {
    sum = ((x >= 0) ? pi_2 : -pi_2) - sum;
  }
  return sum;
}
