#include "arcsin.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

double evstyunichev::arcsin(double x, size_t k, double error)
{
  const char *errmsg = "<MATH ERROR>";
  double last = x, ans = x;
  for (size_t i = 1; i < k; i++)
  {
    last = last * x * x * (i * 2 - 1) * (i * 2 - 1) / (i * 2 + 0.0) / (i * 2 + 1.0);
    ans += last;
  }
  if (std::abs(last) > error)
  {
    throw std::logic_error(errmsg);
  }
  return ans;
}

double evstyunichev::stdarcsin(double x)
{
  return std::asin(x);
}

void evstyunichev::output(double x, size_t k, double error)
{
  constexpr size_t field_size = 12;
  std::cout << std::setw(field_size) << x << "    ";
  try
  {
    std::cout << std::setw(field_size) << evstyunichev::arcsin(x, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(field_size) << e.what();
  }
  std::cout << std::setw(field_size) << evstyunichev::stdarcsin(x);
}
