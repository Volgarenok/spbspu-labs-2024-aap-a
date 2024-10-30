#include "titletaylor.h"
#include <iostream>
#include <iomanip>
#include <cstring>

void duhanina::output(const double i, const size_t k, const double error)
{
  constexpr const char * errormsg = "<MATH ERROR>";
  constexpr size_t sec_column_width = std::strlen(errormsg);
  constexpr size_t oth_columns = 10;
  std::cout << std::setw(oth_columns) << i;
  std::cout << " ";
  try
  {
    std::cout << std::setw(sec_column_width) << duhanina::calcValue(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(sec_column_width) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(oth_columns) << duhanina::calcValueStd(i);
  std::cout << "\n";
}

