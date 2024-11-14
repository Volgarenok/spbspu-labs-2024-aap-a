#ifndef OUTPUT_H
#define OUTPUT_H
#include <cstddef>
namespace asafov
{

  void output(double left, double right, double step, std::size_t numberMax, double error);
  void asafov::writeLine(double x, size_t k, double error);
  void asafov::makeLine(int a, char b);
}
#endif
