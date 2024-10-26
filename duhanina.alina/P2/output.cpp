#include "namespaces.h"
#include <iomanip>
#include <cstring>

void duhanina::output(double i, const size_t k, const double error)
{
  const char * errormsg = "<MATH ERROR>";
  const size_t sec_column_width = std::strlen(errormsg);
  const size_t oth_columns = 10;
  std::cout << std::setw(oth_columns) << i;
  std::cout << " ";
  try
  {
    std::cout << std::setw(sec_column_width) << duhanina::f_taylor(i, k, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(sec_column_width) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(oth_columns) << duhanina::stdf_taylor(i);
  std::cout << "\n";
}

