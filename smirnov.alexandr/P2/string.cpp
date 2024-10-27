#include "Table.hpp"
#include "TaylorSeries.hpp"

void smirnov::outString(double x, size_t k, double error)
{
  const char * errormsg = "MATH ERROR";
  const size_t second_column_width = std::strlen(errormsg) + 2;
  const size_t others_columns = 10;
  size_t snd = second_column_width;
  size_t oth = others_columns;
  std::cout.precision(3);
  std::cout << std::setw(oth) << std::fixed << x << " ";
  try
  {
    std::cout << std::setw(snd) << smirnov::sinTaylor(x, k, error);
  }
  catch(const std::logic_error & e)
  {
    std::cout << std::setw(snd) << "<MATH ERROR>";
  }
  std::cout << " " << std::setw(oth) << smirnov::sinCmath(x) << "\n";
}
