#include "string_input.hpp"

#include <iostream>
#include <ios>

std::istream& rychkov::getline(std::istream& inpStream, char* buf, size_t bufLen, char endChar, size_t* wereRead)
{
  std::ios_base::fmtflags savedInpStreamState = inpStream.flags();
  inpStream >> std::noskipws;
  for (size_t i = 0; i + 1 < bufLen; i++)
  {
    if (!(inpStream >> buf[i]) || (buf[i] == endChar))
    {
      inpStream.flags(savedInpStreamState);
      buf[i] = '\0';
      if (wereRead)
      {
        *wereRead = i;
      }
      return inpStream;
    }
  }

  inpStream.flags(savedInpStreamState);
  if (bufLen != 0)
  {
    buf[bufLen - 1] = '\0';
  }
  if (wereRead)
  {
    *wereRead = (bufLen != 0 ? bufLen - 1 : 0);
  }
  return inpStream;
}
