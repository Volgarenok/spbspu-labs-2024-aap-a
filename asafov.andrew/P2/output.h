#ifndef OUTPUT_H
#define OUTPUT_H
#include <cstddef>
namespace asafov
{
  void output(double left, double right, double step, size_t numberMax, double error);
  void writeLine(double x, size_t k, double error);
  void makeLine(int a, char b);
}
#endif
