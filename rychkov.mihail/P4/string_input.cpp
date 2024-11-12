#include "string_input.hpp"

#include <iostream>
#include <ios>

size_t rychkov::getline(std::istream& inpStream, char* buf, size_t bufLen, char endChar)
{
  std::ios_base::fmtflags savedInpStreamState = inpStream.flags();
  inpStream >> std::noskipws;
  for (size_t i = 0; i + 1 < bufLen; i++)
  {
    if(!(inpStream >> buf[i]) || (buf[i] == endChar))
    {
      inpStream.flags(savedInpStreamState);
      buf[i] = '\0';
      return i;
    }
  }
  inpStream.flags(savedInpStreamState);
  if(bufLen != 0)
  {
    buf[bufLen - 1] = '\0';
    return bufLen - 1;
  }
  return 0;
}
