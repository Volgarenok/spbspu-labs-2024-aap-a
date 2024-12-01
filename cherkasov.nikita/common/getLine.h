#ifndef GETLINE_H
#define GETLINE_H
#include <iostream>

namespace cherkasov
{
  char* inputLine(std::istream& in);
  char* newArrray(char* oldArray, size_t newCapasity);
}

#endif
