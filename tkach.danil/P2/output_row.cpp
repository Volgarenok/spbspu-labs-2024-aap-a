#include "tableoutput.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include "taylorrow.h"

void tkach::outputRow(double start, size_t maxamount, const double error)
{
  constexpr size_t setwx = 13, precision_for_second = 4, precision_for_third = 4, precision_for_first = 2;
  constexpr const char *errormsg = "<MATH ERROR>";
  constexpr size_t error_len = std::strlen(errormsg) + 5;
  std::cout << std::fixed;
  std::cout << std::setw(setwx) << std::setprecision(precision_for_first) <<  start;
  std::cout << " ";
  try
  {
    std::cout << std::setw(setwx)  << std::setprecision(precision_for_second) <<  tkach::coshTaylor(start, maxamount, error) << " ";
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(error_len) << "<MATH ERROR>";
    std::cout << " ";
  }
  std::cout << std::setw(setwx) << std::setprecision(precision_for_third) << tkach::stdCosh(start);
}
