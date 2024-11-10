#ifndef STRINGMANIPULATOR_HPP
#define STRINGMANIPULATOR_HPP

#include <cstddef>
#include <iostream>

namespace maslov
{
  char * inputLine(std::istream & in, char stop);
  char * excludeCharacters(const char * str1, const char * str2);
}

#endif
