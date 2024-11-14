#ifndef STRINGMANIPULATOR_HPP
#define STRINGMANIPULATOR_HPP

#include <iostream>

namespace maslov
{
  char * inputLine(std::istream & in, char stop);
  char * excludeCharacters(char * str1, const char * str2);
}

#endif
