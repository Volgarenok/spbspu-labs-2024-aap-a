#include "inputMtrx.hpp"

std::istream & shramko::inputMtrx(std::istream & in, int* mtrx, size_t sizeMtrx)
{
  for (size_t i = 0; i < sizeMtrx; i++)
  {
    if (!(in >> mtrx[i]))
    {
      return in;
    }
  }
  return in;
}
