#include "brain.h"
#include <iostream>
#include <iomanip>
#include <cstring>
void bocharov::table(double number, size_t k, double error)
{
  const int n = 3;
  double (*a[])(double, size_t, double) = {bocharov::f, bocharov::f2, bocharov::sumf};
  std::cout << std::setw(15) << number;
  for (size_t i = 0; i < n; i++)
  {
    try
    {
      std::cout << std::setw(15) << a[i](number, k, error);
    }
    catch (const std::logic_error &e)
    {
      std::cout << std::setw(15) << "Math error";
    }
  }
  std::cout << std::setw(15) << bocharov::sqrt1_x(number);
  std::cout << std::setw(15) << bocharov::ln(number);
  std::cout << std::setw(15) << bocharov::sumf2(number) << "\n";
}
