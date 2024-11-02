#include "taylor.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

namespace cherkasov
{
  double getTaylor(double x, size_t k, double error)
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
  double get_exp(double x)
  {
    return std::exp(x) - x;
  }
  void generating_exception()
  {
    std::cerr << "<MATH ERROR>" << "\n";
  }
  void get_table(double x, double getTaylor_value, double get_exp_value, size_t col_width, size_t others_columns)
  {
    std::cout.width(others_columns);
    std::cout << x << " ";
    std::cout.width(col_width);
    std::cout << getTaylor_value << " ";
    std::cout.width(others_columns);
    std::cout << get_exp_value << "\n";
  }
  void processValue(double x, size_t k, double error, size_t col_width, size_t others_columns)
  {
    double taylor_value;
    try
    {
      taylor_value = cherkasov::getTaylor(x, k, error);
    }
    catch (const std::logic_error&)
    {
      cherkasov::generating_exception();
      std::cout << " ";
      std::cout.width(others_columns);
      std::cout << cherkasov::get_exp(x);
      std::cout << "\n";
      return;
    }
      double exp_value = cherkasov::get_exp(x);
      cherkasov::get_table(x, taylor_value, exp_value, col_width, others_columns);
  }
}
