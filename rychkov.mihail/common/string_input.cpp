#include "string_input.hpp"

#include <iostream>
#include <ios>

#include <memf.hpp>

std::istream& rychkov::getline(std::istream& inpStream, char* buf, size_t bufLen, char endChar, size_t* wereRead)
{
  std::ios_base::fmtflags savedInpStreamState = inpStream.flags();
  inpStream >> std::noskipws;
  for (size_t i = 0; i + 1 < bufLen; i++)
  {
    if (!(inpStream >> buf[i]) || (buf[i] == endChar))
    {
      inpStream.flags(savedInpStreamState);
      if (inpStream.eof())
      {
        inpStream.clear();
        inpStream.setstate(std::ios_base::eofbit);
      }

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

char* rychkov::getline(std::istream& inpStream, char endChar, size_t* wereRead)
{
  constexpr size_t defaultStringLength = 7;
  char* str = reinterpret_cast< char* >(malloc(defaultStringLength * sizeof(char)));
  if (!str)
  {
    inpStream.setstate(std::ios_base::failbit);
    return nullptr;
  }
  str[0] = '\0';
  size_t strLength = defaultStringLength;

  size_t tempWereRead = 0;
  if (!wereRead)
  {
    wereRead = &tempWereRead;
  }

  size_t wPoint = 0;
  while (rychkov::getline(std::cin, str + wPoint, strLength - wPoint, endChar, wereRead)
      && (*wereRead == strLength - wPoint - 1))
  {
    wPoint = strLength - 1;

    size_t newSize = 2 * strLength + 1;
    char* reallocatedStr = rychkov::realloc(str, strLength, newSize);
    if (!reallocatedStr)
    {
      inpStream.setstate(std::ios_base::failbit);
      return str;
    }
    str = reallocatedStr;
    strLength = newSize;
  }
  return str;
}
