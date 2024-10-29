#include "arctanTaylor.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>

void timofeev::matrix_output(double start, double end, size_t number_max, double abs_error, double step)
{
  constexpr char * er_math = "<MATH ERROR>";
  constexpr size_t dlina_er = std::strlen(er_math);
  for (double x = start; x < end; x += step) {
    std::cout << std::setw(dlina_er) << x;
    try
    {
      std::cout << std::setw(dlina_er) << timofeev::arctan_taylor(x, abs_error, number_max);
    }
    catch (constexpr std::logic_error & e)
    {
      std::cout << std::setw(dlina_er) << "<MATH ERROR>";
    }
    std::cout << std::setw(dlina_er) << atan(x);
    std::cout << "\n";
  }
}
