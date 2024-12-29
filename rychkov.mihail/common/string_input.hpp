#ifndef STRING_INPUT_HPP
#define STRING_INPUT_HPP

#include <cstddef>
#include <iosfwd>

namespace rychkov
{
  std::istream& getline(std::istream& inpStream, char* buf, size_t bufLen, char endChar = '\n', size_t* wereRead = nullptr);
  char* getline(std::istream& inpStream, char endChar = '\n', size_t* wereRead = nullptr);
}

#endif
