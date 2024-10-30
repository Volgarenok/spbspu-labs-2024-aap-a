#ifndef CREATE_TABLE_HPP
#define CREATE_TABLE_HPP
#include <cstddef>
namespace karnauhova
{
  void output_row(double x, size_t k, double error, size_t width);
  void output_table(double left, double right, double step, size_t k, double error, size_t width);
}
#endif
