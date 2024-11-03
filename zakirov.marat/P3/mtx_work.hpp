#ifndef MTX_WORK_HPP
#define MTX_WORK_HPP
#include <iostream>
namespace zakirov
{
  std::istream & input_mtx(std::istream & in, int * mtx, size_t columns, size_t rows);
  int * transform_mtx(int * mtx, size_t columns, size_t rows);
  size_t output_mtx(int * mtx, size_t columns, size_t rows);
}
#endif
