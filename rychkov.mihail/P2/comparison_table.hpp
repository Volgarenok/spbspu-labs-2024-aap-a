#ifndef COMPARISON_TABLE_HPP
#define COMPARISON_TABLE_HPP

#include <cstddef>
#include <ostream>

namespace rychkov
{
  void printTable(std::ostream& outstream, double left, double right,
      double step, size_t maxDepth, double absError);
  void printLine(std::ostream& outstream, double x, size_t maxDepth, double absError);
}

#endif
