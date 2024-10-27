#include <iostream>
#include <iomanip>
#include "arctanTaylor.h"
#include <cstring>
#include <stdexcept>

void timofeev::MatrixOutput(double start, double end, size_t numberMax, double absError, double step)
{
  const char * er_math = "<MATH ERROR>";
  const size_t dlina_er = std::strlen(er_math);
  for (double x = start; x < end; x += step)
  {
    std::cout << std::setw(dlina_er) << x;
    try
    {
      std::cout << std::setw(dlina_er) << timofeev::arctanTaylor(x, absError, numberMax);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(dlina_er) << "<MATH ERROR>";
    }
    std::cout << std::setw(dlina_er) << atan(x);
    std::cout << "\n";
  }
}
