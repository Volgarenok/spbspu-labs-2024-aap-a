#ifndef TABLEOUTPUT_H
#define TABLEOUTPUT_H
#include <cstddef>

namespace tkach
{
  void outputTable(double start, double end, size_t maxkolvo, double error, double step);
  void outputRow(double start, size_t maxkolvo, double error);
}

#endif
