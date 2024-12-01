#include "getline.hpp"
#include <ios>
#include <stdexcept>

char *sveshnikov::read_str(std::istream &in, std::size_t &len)
{
  std::size_t max_len = 100, size = 0;
  char *str = new char[max_len];
  char c = '\0';
  std::noskipws(in);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == max_len - 1)
    {
      max_len += 100;
      str[size] = '\0';
      char *new_str = nullptr;
      try
      {
        new_str = memory_alloc(str, max_len);
      }
      catch (const std::bad_alloc &e)
      {
        std::skipws(std::cin);
        delete[] str;
        throw;
      }
      delete[] str;
      str = new_str;
    }
    str[size++] = c;
  }
  str[size] = '\0';
  len = size;
  std::skipws(std::cin);
  return str;
}
