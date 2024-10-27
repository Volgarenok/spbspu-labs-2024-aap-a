#ifndef COMPARISON_TABLE_HPP
#define COMPARISON_TABLE_HPP

#include <cstddef>

namespace rychkov
{
  namespace comparison_utilities
  {
    void printTable(double left, double right, double step, size_t maxDepth, double absError);
    void printLine(double x, size_t maxDepth, double absError);
  }
}

#endif
