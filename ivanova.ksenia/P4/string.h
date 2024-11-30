#ifndef STRING_H
#define STRING_H

namespace ivanova
{
  char* getLine(std::istream& in);
  char* moreSpace(const char* string, size_t newSize);
}

#endif
