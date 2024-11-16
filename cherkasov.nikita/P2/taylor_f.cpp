#include "taylor_f.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

double cherkasov::getTaylor(double x, size_t k, double error)
{
  double next = 1;
  double result = next;

  for (size_t i = 1; i < k; ++i)
  {
    next *= x / i;
    result += next;

    if (std::abs(next) < error)
    {
      return result - x;
    }
  }

  throw std::logic_error("math-error");
}

double cherkasov::getExp(double x)
{
  return std::exp(x) - x;
}

void cherkasov::generatingException()
{
  std::cerr << "<MATH ERROR>" << "\n";
}

void cherkasov::getTable(double x, double taylor_value, double exp_value, size_t column_width, size_t other_columns)
{
  std::cout.width(other_columns);
  std::cout << x << " ";
  std::cout.width(column_width);
  std::cout << taylor_value << " ";
  std::cout.width(other_columns);
  std::cout << exp_value << "\n";
}

void cherkasov::processValue(double x, size_t k, double error, size_t column_width, size_t other_columns)
{
  double taylor_value;
  try
  {
    taylor_value = cherkasov::getTaylor(x, k, error);
  }
    catch (const std::logic_error&)
    {
      cherkasov::generatingException();
      std::cout << " ";
      std::cout.width(other_columns);
      std::cout << cherkasov::getExp(x);
      std::cout << "\n";
      return;
    }

  double exp_value = cherkasov::getExp(x);
  cherkasov::getTable(x, taylor_value, exp_value, column_width, other_columns);
}
