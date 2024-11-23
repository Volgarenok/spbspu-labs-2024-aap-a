#ifndef INPUTSTRING_H
#define INPUTSTRING_H
#include <iostream>
namespace kiselev
{
  char* resizeArr(const char* array, size_t newLength, size_t pastLength);
  char* inputString(std::istream& input, char end);
}
#endif
