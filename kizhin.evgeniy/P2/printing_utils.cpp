#include "printing_utils.hpp"

#include <iomanip>

void kizhin::printCell(std::ostream& os, double data, size_t width, size_t precision)
{
  os << std::setw(width) << std::left << std::setprecision(precision) << data;
}
void kizhin::printCell(std::ostream& os, const char* data, size_t width, size_t precision)
{
  os << std::setw(width) << std::left << std::setprecision(precision) << data;
}

void kizhin::printRow(std::ostream& os, double argument, const char* errorMessage,
                      double expectedValue)
{
  printCell(os, argument);
  printCell(os, errorMessage);
  printCell(os, expectedValue);
  os << '\n';
}
void kizhin::printRow(std::ostream& os, double argument, double computedValue, double expectedValue)
{
  printCell(os, argument);
  printCell(os, computedValue);
  printCell(os, expectedValue);
  os << '\n';
}
