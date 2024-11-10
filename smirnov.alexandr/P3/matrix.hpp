#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <iostream>

namespace smirnov
{
  void lft_top_clk(int * matrix, size_t rows, size_t columns);
  bool lwr_tri_mtx(int * matrix, size_t rows, size_t columns);
  std::istream & inputMatrix(std::istream & input, int * matrix, size_t rows, size_t cols);
  void lft_top_clkOutput(std::ostream & output, int * matrix, size_t rows, size_t columns);
  void lwr_tri_mtxOutput(std::ostream & output, int * matrix, size_t rows, size_t columns);
}
#endif
