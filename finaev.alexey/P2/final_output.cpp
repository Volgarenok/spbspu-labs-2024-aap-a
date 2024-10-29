#include "tyler_row.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdexcept>

void finaev::final_output(double left, double right, size_t k, double error, double step)
{
  constexpr const char * er_math = "<MATH ERROR>";
  constexpr size_t second_dl = std::strlen(er_math);
  constexpr size_t other_dl = 10;
  for (auto i = left; i <= right; i += step)
  {
    std::cout << std::setw(other_dl) << i;
    try
    {
      std::cout << std::setw(second_dl) << finaev::fsqrt(i, k, error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(second_dl) << "<MATH ERROR>";
    }
    std::cout << std::setw(other_dl) << finaev::basesqrt(i);
    std::cout << "\n";
  }
}
