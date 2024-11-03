#include "mtx_work.hpp"

std::istream & zakirov::input_mtx(std::istream & in, int * mtx, size_t columns, size_t rows)
{
  for (size_t i = 0; i < columns*rows; ++i)
  {
    in >> mtx[i];
  }
  return in;
}
