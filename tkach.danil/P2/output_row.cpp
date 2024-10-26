#include <iostream>
#include <iomanip>
#include "all.h"

void tkach::output_row(double start, size_t maxkolvo, const double error)
{
  const size_t setwx = 13;
  std::cout << std::setw(setwx) << start;
  std::cout << " ";
  try
  {
    std::cout << std::setw(setwx) << std::setprecision(4) <<  tkach::teylor_row(start, maxkolvo, error) << " ";
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << std::setw(setwx) << std::setprecision(4) << tkach::stdmath(start) << "\n";
}
