#include "inputString.hpp"
#include "resizeString.hpp"
char* inputString(std::istream &in)
{
  const size_t iterSize = 100;
  size_t strSize = iterSize;
  char *str = static_cast<char*>(malloc(sizeof(char) * iterSize));
  char ch = 0;
  size_t i = 0;
  in >> std::noskipws;
  while (in >> ch)
  {
    if (ch == '\n')
    {
      break;
    }
    if (i == strSize)
    {
      char *temp = resizeString(str, strSize, iterSize);
      if (temp == nullptr)
      {
        throw std::bad_alloc("incorrect memory allocation")
      }
      strSize += iterSize;
      free(str)
      str = temp;
    }
  }
  temp[i] = ch;
  ++i;
  temp[i] = '\0';
  in >> std::skipws;
  return str;
}
