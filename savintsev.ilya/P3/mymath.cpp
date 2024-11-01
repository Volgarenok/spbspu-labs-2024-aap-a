#include "mymath.h"

bool savintsev::isDigit(char c)
{
  return (c >= '0' && c <= '9') ? true : false;
}
size_t savintsev::minSizet(size_t a, size_t b)
{
  return (a < b) ? a : b;
}
