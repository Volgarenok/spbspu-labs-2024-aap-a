#include "rep_sym.hpp"
#include <ios>
#include <stdexcept>

char *sveshnikov::read_str(std::istream &in, char *str, std::size_t *len)
{
  std::size_t size = 0;
  char c = '\0';
  std::noskipws(in);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == *len)
    {
      try
      {
        *len += 100;
        char *longer_str = nullptr;
        longer_str = new char[*len];
        for (std::size_t i = 0; i < *len - 100; i++)
        {
          longer_str[i] = str[i];
        }
        delete[] str;
        str = longer_str;
      }
      catch (const std::bad_alloc &e)
      {
        throw;
      }
    }
    str[size++] = c;
  }
  if (!std::cin)
  {
    throw std::istream::failure("ERROR: can not read");
  }
  str[size] = '\0';
  std::skipws(std::cin);
  return str;
}
