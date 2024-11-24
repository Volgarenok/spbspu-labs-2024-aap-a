#ifndef GETSTRING_H
#define GETSTRING_H

#include <ios>
#include <cstddef>

namespace aleksandrov
{
  char* getString(std::istream& input);
  char* copyString(const char* str, size_t newStrSize);
}

#endif

