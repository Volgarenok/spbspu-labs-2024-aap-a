#ifndef PRINT_COMPARISON_TABLE_HPP
#define PRINT_COMPARISON_TABLE_HPP

#include <cstddef>

namespace rychkov
{
  namespace comparison
  {
    void printTable(double left, double right, double step, size_t maxDepth, double absError);
    void printLine(double x, size_t maxDepth, double absError);
  }
}

#endif
