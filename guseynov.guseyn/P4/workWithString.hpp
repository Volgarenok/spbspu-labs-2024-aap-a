#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP
#include <iostream>
namespace guseyn
{
  char * inputLine(std::istream & in, char stop);
  size_t identifyUniqueChar(char *inputString, char *uniqueChars, size_t num);
}
#endif
