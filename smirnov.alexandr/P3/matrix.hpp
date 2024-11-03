#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace smirnov
{
  void processMatrix(int ** matrix, int rows, int cols, std::ofstream & output);
}
#endif
