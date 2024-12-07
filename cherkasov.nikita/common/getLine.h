#ifndef GETLINE_H
#define GETLINE_H
#include <iostream>
#include <cstddef>

namespace cherkasov
{
  char* inputLine(std::istream& in);
  char* newArray(const char* oldArray, size_t newCapasity);
}

#endif
