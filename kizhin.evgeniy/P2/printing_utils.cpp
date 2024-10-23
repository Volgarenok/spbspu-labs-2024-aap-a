#include "printing_utils.hpp"

#include <iomanip>

template <typename T>
void kizhin::printCell(std::ostream& os, const T& data, size_t width, size_t precision)
{
  os << std::setw(width) << std::left << std::setprecision(precision) << data;
}

template <typename T>
void kizhin::printRow(std::ostream& os, double argument, const T& computedValue,
                      double expectedValue)
{
  printCell(os, argument);
  printCell(os, computedValue);
  printCell(os, expectedValue);
  os << '\n';
}

template void kizhin::printRow<double>(std::ostream&, double, const double&, double);
template void kizhin::printRow<char const*>(std::ostream&, double, const char* const&, double);
