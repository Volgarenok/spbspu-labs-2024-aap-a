#ifndef GETLINE_H
#define GETLINE_H
#include <iostream>

namespace cherkasov
{
  void copyArray(const char* src, char* dest, size_t length);
  char* inputLine(std::istream& in, size_t& length);
}
#endif
