#include "arctanTaylor.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <stdexcept>

void timofeev::print_matrix(double start, double end, size_t number_max, double abs_error, double step)
{
  const char * er_math = "<MATH ERROR>";
  const size_t length_er = std::strlen(er_math);
  for (double x = start; x < end; x += step)
  {
    std::cout << std::setw(length_er) << x;
    try
    {
      std::cout << std::setw(length_er) << timofeev::cal_arctan_taylor(x, abs_error, number_max);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(length_er) << "<MATH ERROR>";
    }
    std::cout << std::setw(length_er) << std::atan(x);
    std::cout << "\n";
  }
}
