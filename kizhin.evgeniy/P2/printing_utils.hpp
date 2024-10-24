#ifndef PRINTING_UTILS_HPP
#define PRINTING_UTILS_HPP

#include <ostream>

namespace kizhin {
  constexpr size_t defaultColumnWidth = 20;
  constexpr size_t defaultPrecision = 10;

  void printCell(std::ostream& os, const char* data, size_t width = defaultColumnWidth,
                 size_t precision = defaultPrecision);
  void printCell(std::ostream& os, double data, size_t width = defaultColumnWidth,
                 size_t precision = defaultPrecision);

  void printRow(std::ostream& os, double argument, double computedValue, double expectedValue);
  void printRow(std::ostream& os, double argument, const char* errorMessage, double expectedValue);
}

#endif
