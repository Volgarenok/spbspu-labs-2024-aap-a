#include "findMin.hpp"
#include "findTwoMin.hpp"

char dirti::findMin(const char * str)
{
  char str_min2[2] = {'0', '0'};
  dirti::findTwoMin(str, str_min2);
  char sym_out = str_min2[0];
  return sym_out;
}
