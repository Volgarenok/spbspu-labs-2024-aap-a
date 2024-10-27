#include "taylor_swift.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdexcept>
void lanovenko::laststro(double left, double right, size_t k, double error, double step)
{
  const char * emath = "<MATH ERROR>";
  const size_t second = std::strlen(emath);
  const size_t any  = 10;
  for (auto i = left; i < right; i += step)
  {
    std::cout << std::setw(any) << i;
    try
    {
      std::cout << std::setw(second) << lanovenko::f(i, k, error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(second) << "<MATH ERROR>";
    }
    std::cout << std::setw(any) << lanovenko::sqruno(i);
    std::cout << "\n";
  }
  std::cout << right;
  try
  {
    std::cout << std::setw(second) << lanovenko::f(right, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(second) << "<MATH ERROR>";
  }
  std::cout << std::setw(any) << lanovenko::sqruno(right);
  std::cout << "\n";
}
