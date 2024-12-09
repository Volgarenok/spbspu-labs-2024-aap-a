#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <iosfwd>

namespace kizhin {
  char* readString(std::istream&);
  char* expandString(const char*, size_t newSize);
}

#endif

