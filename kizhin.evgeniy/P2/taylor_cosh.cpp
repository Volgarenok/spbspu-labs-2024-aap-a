#include "taylor_cosh.hpp"
#include <stdexcept>

double kizhin::computeTaylorCosh(double argument, size_t maxOperands, double absoluteError)
{
  if (maxOperands == 0 || absoluteError <= 0) {
    throw std::invalid_argument("Invalid function arguments");
  }
  double result = 1.0;
  double current = 1.0;
  double error = 1.0;

  for (size_t i = 1; i < maxOperands; ++i) {
    current *= (argument * argument) / (2 * i * (2 * i - 1));
    result += current;
    error = current;
    if (error <= absoluteError) {
      break;
    }
  }
  if (error > absoluteError) {
    throw std::logic_error("Error exceeds allowed limit");
  }
  return result;
}
