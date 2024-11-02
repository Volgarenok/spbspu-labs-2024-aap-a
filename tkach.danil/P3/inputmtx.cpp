#include "filemtx.h"

std::istream & tkach::inputMtx(std::istream & in, int* const mtx1, const size_t str, const size_t stl)
{
  for (size_t i = 0; i < str; ++i)
  {
    for (size_t j = 0; j < stl; ++j)
    {
      in >> mtx1[i * stl + j];
    }
  }
  return in;
}
