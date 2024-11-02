#include "filemtx.h"

std::istream & tkach::inputMtx(std::istream & in, int* const mtx1, const size_t str)
{
  for (size_t i = 0; i < str; ++i)
  {
    for (size_t j = 0; j < str; ++j)
    {
      in >> mtx1[i*str+j];
    }
  }
  return in;
}