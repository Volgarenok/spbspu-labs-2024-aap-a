#ifndef STRING_INPUT_HPP
#define STRING_INPUT_HPP

#include <cstddef>
#include <iosfwd>

namespace rychkov
{
  size_t getline(std::istream& inpStream, char* buf, size_t bufLen, char endChar = '\n');
}

#endif
