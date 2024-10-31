#include "row.h"
#include <stdexcept>

void aleksandrov::printRow(double i, size_t k, double error)
{
  constexpr const char* errorMessage = "<MATH ERROR>";
  constexpr size_t columnWidth = std::strlen(errorMessage);
  std::cout << std::setw(columnWidth) << std::left << std::fixed << std::setprecision(5) << i;
  try
  {
    std::cout << std::setw(columnWidth) << std::left << std::fixed << std::setprecision(5);
    std::cout << taylor(i, k, error);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(columnWidth) << std::left;
    std::cout << errorMessage;
  }
  try
  {
    std::cout << std::setw(columnWidth) << std::right << std::fixed << std::setprecision(5);
    std::cout << sinxDivx(i);
  }
  catch (const std::logic_error& e)
  {
    std::cout << std::setw(columnWidth) << std::left << errorMessage;
  }
}
