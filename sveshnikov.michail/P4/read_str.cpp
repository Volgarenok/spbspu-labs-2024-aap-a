#include "rep_sym.hpp"
#include <ios>

char *sveshnikov::read_str(std::istream &in, char *str, std::size_t *len)
{
  std::size_t size = 0;
  char c = '\0';
  std::noskipws(in);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == *len)
    {
      str = sveshnikov::memory_alloc(str, len);
      if (str == nullptr)
      {
        return nullptr;
      }
    }
    str[size++] = c;
  }
  if (!std::cin)
  {
    return nullptr;
  }
  str[size] = '\0';
  std::skipws(std::cin);
  return str;
}
