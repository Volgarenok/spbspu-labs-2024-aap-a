#ifndef TABLEOUTPUT_H
#define TABLEOUTPUT_H
#include <cstddef>

namespace tkach
{
  void outputTable(double start, double end, size_t maxkolvo, const double error, const double step);
  void outputRow(double start, size_t maxkolvo, const double error);
}

#endif
