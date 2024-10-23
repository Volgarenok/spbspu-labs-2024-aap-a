#include "table.h"
#include "partOfRow.cpp"
#include <cmath>
#include <iostream>

void shramko::table(double left, double right, size_t k)
{
  const double step = 0.2;
  const double error = 0,001;

  while (size_t i = left; i < right; i += step)
  {
    double value = shramko::partOfRow(i, k, error)

    if (i > right)
    {
      return 0;
    }

    if (i == right)
    {
      std::cout << left << " ";
      try
      {
        std::cout << value << " ";
      }
      catch
      {
        std::cout << "<MATH ERROR>" << " ";
      }
      std::cout << std::sin(left) << "\n";
      return 0;
    }

    std::cout << left << " ";
    try
    {
      std::cout << value << " ";
    }
    catch
    {
      std::cout << "<MATH ERROR>" << " ";
    }
    std::cout << std::sin(left) << "\n";
  }
}
