#ifndef OUTPUT_TABLE_HPP
#define OUTPUT_TABLE_HPP

#include <ostream>

namespace kizhin
{
constexpr size_t defaultColumnWidth = 20;
constexpr size_t defaultPrecision = 10;

template <typename T>
void printCell(std::ostream& os, const T& data,
               size_t width = defaultColumnWidth,
               size_t precision = defaultPrecision);

template <typename T>
void printRow(std::ostream& os, double argument, const T& computedValue,
              double expectedValue);
}

#endif
