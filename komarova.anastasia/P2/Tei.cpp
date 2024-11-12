#include "tableTeilor.h"
#include <cstddef>
#include <stdexcept>

double komarova::teilor(double x, size_t  k, double error)
{
  double sumi = x;
  int denom = 2;
  int numer = 1;
  int d = 1;
  double slag = 1.0;
  for (size_t i = 1; i < k; i++)
  {
    slag = (-1) * slag * x * x * numer * d / (denom * (d + 2));
    sumi += slag;
    numer += 2;
    denom += 2;
    d += 2;
  }
  if (slag > error)
  {
    throw std::logic_error("MATH ERROR");
  }
  else
  {
    return sumi;
  }
}
