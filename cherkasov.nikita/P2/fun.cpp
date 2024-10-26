#include <iostream>
#include <cmath>
#include <stdexcept>
#include "fun.h"

namespace cherkasov
{
  double Taylor(double x, size_t k, double error)
  {
    double next = 1;
    double result = next;
    for (size_t i = 1; i < k; ++i)
    {
      next *= x/i;
      result += next;
      if (std::abs(next) < error)
      {
        return result - x;
      }
    }
    throw std::logic_error("math-error");
  }
  double exp(double x)
  {
    return std::exp(x) - x;
  }
  void exception()
  {
    std::cerr << "<MATH ERROR>" << "\n";
  }
  void table(double i, double Taylor_value, double exp_value, size_t colWidth, size_t others_columns)
  {
    std::cout.width(others_columns);
    std::cout << i << " ";
    std::cout.width(colWidth);
    std::cout << Taylor_value << " ";
    std::cout.width(others_columns);
    std::cout << exp_value << "\n";
  }
}
