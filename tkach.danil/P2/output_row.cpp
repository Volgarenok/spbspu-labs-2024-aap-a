#include <iostream>
#include "all.h"

void tkach::output_row(double start, size_t maxkolvo, const double error)
{
  std::cout << start << " ";
  try
  {
    std::cout << tkach::teylor_row(start, maxkolvo, error) << " ";
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>\n";
  }
  std::cout << tkach::stdmath(start) << "\n"; 
}
